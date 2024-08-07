#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {TYPE_2__* adap; } ;
struct tda18271_priv {int config; int /*<<< orphan*/  mode; TYPE_1__ i2c_props; } ;
struct dvb_frontend {int (* callback ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;struct tda18271_priv* tuner_priv; } ;
struct TYPE_4__ {int /*<<< orphan*/  algo_data; } ;

/* Variables and functions */
 int DBG_ADV ; 
 int /*<<< orphan*/  DVB_FRONTEND_COMPONENT_TUNER ; 
 int EINVAL ; 
 int /*<<< orphan*/  TDA18271_CALLBACK_CMD_AGC_ENABLE ; 
#define  TDA8290_LNA_GP0_HIGH_OFF 131 
#define  TDA8290_LNA_GP0_HIGH_ON 130 
#define  TDA8290_LNA_OFF 129 
#define  TDA8290_LNA_ON_BRIDGE 128 
 int stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int tda18271_debug ; 
 int /*<<< orphan*/  tda_dbg (char*) ; 
 int /*<<< orphan*/  tda_err (char*,int) ; 

__attribute__((used)) static int tda18271_agc(struct dvb_frontend *fe)
{
	struct tda18271_priv *priv = fe->tuner_priv;
	int ret = 0;

	switch (priv->config) {
	case TDA8290_LNA_OFF:
		/* no external agc configuration required */
		if (tda18271_debug & DBG_ADV)
			tda_dbg("no agc configuration provided\n");
		break;
	case TDA8290_LNA_ON_BRIDGE:
		/* switch with GPIO of saa713x */
		tda_dbg("invoking callback\n");
		if (fe->callback)
			ret = fe->callback(priv->i2c_props.adap->algo_data,
					   DVB_FRONTEND_COMPONENT_TUNER,
					   TDA18271_CALLBACK_CMD_AGC_ENABLE,
					   priv->mode);
		break;
	case TDA8290_LNA_GP0_HIGH_ON:
	case TDA8290_LNA_GP0_HIGH_OFF:
	default:
		/* n/a - currently not supported */
		tda_err("unsupported configuration: %d\n", priv->config);
		ret = -EINVAL;
		break;
	}
	return ret;
}