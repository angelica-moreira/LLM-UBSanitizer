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
struct i2c_msg {int /*<<< orphan*/  len; int /*<<< orphan*/ * buf; int /*<<< orphan*/  addr; int /*<<< orphan*/  flags; } ;
struct dvb_pll_priv {int /*<<< orphan*/ * i2c; TYPE_1__* pll_desc; int /*<<< orphan*/  pll_i2c_address; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* i2c_gate_ctrl ) (struct dvb_frontend*,int) ;} ;
struct dvb_frontend {TYPE_2__ ops; struct dvb_pll_priv* tuner_priv; } ;
struct TYPE_3__ {int /*<<< orphan*/ * initdata2; int /*<<< orphan*/ * initdata; } ;

/* Variables and functions */
 int EINVAL ; 
 int i2c_transfer (int /*<<< orphan*/ *,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  stub1 (struct dvb_frontend*,int) ; 
 int /*<<< orphan*/  stub2 (struct dvb_frontend*,int) ; 

__attribute__((used)) static int dvb_pll_init(struct dvb_frontend *fe)
{
	struct dvb_pll_priv *priv = fe->tuner_priv;

	if (priv->i2c == NULL)
		return -EINVAL;

	if (priv->pll_desc->initdata) {
		struct i2c_msg msg = { .flags = 0,
			.addr = priv->pll_i2c_address,
			.buf = priv->pll_desc->initdata + 1,
			.len = priv->pll_desc->initdata[0] };

		int result;
		if (fe->ops.i2c_gate_ctrl)
			fe->ops.i2c_gate_ctrl(fe, 1);
		result = i2c_transfer(priv->i2c, &msg, 1);
		if (result != 1)
			return result;
		if (priv->pll_desc->initdata2) {
			msg.buf = priv->pll_desc->initdata2 + 1;
			msg.len = priv->pll_desc->initdata2[0];
			if (fe->ops.i2c_gate_ctrl)
				fe->ops.i2c_gate_ctrl(fe, 1);
			result = i2c_transfer(priv->i2c, &msg, 1);
			if (result != 1)
				return result;
		}
		return 0;
	}
	/* Shouldn't be called when initdata is NULL, maybe BUG()? */
	return -EINVAL;
}