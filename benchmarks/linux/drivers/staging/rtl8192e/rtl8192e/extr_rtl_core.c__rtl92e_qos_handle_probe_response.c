#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct rtllib_qos_parameters {int dummy; } ;
struct TYPE_8__ {int active; int supported; scalar_t__ old_param_count; scalar_t__ param_count; int /*<<< orphan*/  wmm_acm; } ;
struct rtllib_network {int flags; TYPE_4__ qos_data; } ;
struct r8192_priv {int /*<<< orphan*/  qos_activate; TYPE_3__* rtllib; } ;
struct TYPE_5__ {int /*<<< orphan*/  parameters; } ;
struct TYPE_6__ {TYPE_1__ qos_data; } ;
struct TYPE_7__ {scalar_t__ state; scalar_t__ iw_mode; TYPE_2__ current_network; int /*<<< orphan*/  wmm_acm; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMP_QOS ; 
 scalar_t__ IW_MODE_INFRA ; 
 int NETWORK_HAS_QOS_MASK ; 
 int NETWORK_HAS_QOS_PARAMETERS ; 
 scalar_t__ RTLLIB_LINKED ; 
 int /*<<< orphan*/  RT_TRACE (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  def_qos_parameters ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int _rtl92e_qos_handle_probe_response(struct r8192_priv *priv,
					     int active_network,
					     struct rtllib_network *network)
{
	int ret = 0;
	u32 size = sizeof(struct rtllib_qos_parameters);

	if (priv->rtllib->state != RTLLIB_LINKED)
		return ret;

	if (priv->rtllib->iw_mode != IW_MODE_INFRA)
		return ret;

	if (network->flags & NETWORK_HAS_QOS_MASK) {
		if (active_network &&
				(network->flags & NETWORK_HAS_QOS_PARAMETERS))
			network->qos_data.active = network->qos_data.supported;

		if ((network->qos_data.active == 1) && (active_network == 1) &&
				(network->flags & NETWORK_HAS_QOS_PARAMETERS) &&
				(network->qos_data.old_param_count !=
				network->qos_data.param_count)) {
			network->qos_data.old_param_count =
				network->qos_data.param_count;
			priv->rtllib->wmm_acm = network->qos_data.wmm_acm;
			schedule_work(&priv->qos_activate);
			RT_TRACE(COMP_QOS,
				 "QoS parameters change call qos_activate\n");
		}
	} else {
		memcpy(&priv->rtllib->current_network.qos_data.parameters,
		       &def_qos_parameters, size);

		if ((network->qos_data.active == 1) && (active_network == 1)) {
			schedule_work(&priv->qos_activate);
			RT_TRACE(COMP_QOS,
				 "QoS was disabled call qos_activate\n");
		}
		network->qos_data.active = 0;
		network->qos_data.supported = 0;
	}

	return 0;
}