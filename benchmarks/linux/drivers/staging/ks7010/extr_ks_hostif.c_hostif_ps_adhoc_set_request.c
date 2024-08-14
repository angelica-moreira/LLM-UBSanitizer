#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  channel; } ;
struct ks_wlan_private {TYPE_1__ reg; } ;
struct hostif_ps_adhoc_set_request {int /*<<< orphan*/  channel; int /*<<< orphan*/  request; } ;

/* Variables and functions */
 int /*<<< orphan*/  HIF_PS_ADH_SET_REQ ; 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hif_align_size (int) ; 
 struct hostif_ps_adhoc_set_request* hostif_generic_request (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_request (struct ks_wlan_private*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  send_request_to_device (struct ks_wlan_private*,struct hostif_ps_adhoc_set_request*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static
void hostif_ps_adhoc_set_request(struct ks_wlan_private *priv)
{
	struct hostif_ps_adhoc_set_request *pp;

	pp = hostif_generic_request(sizeof(*pp), HIF_PS_ADH_SET_REQ);
	if (!pp)
		return;

	init_request(priv, &pp->request);
	pp->channel = cpu_to_le16(priv->reg.channel);

	send_request_to_device(priv, pp, hif_align_size(sizeof(*pp)));
}