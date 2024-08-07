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
typedef  int u8 ;
typedef  int u32 ;
struct ttusb {int /*<<< orphan*/  i2c_adap; } ;
struct i2c_msg {int addr; int* buf; int len; int /*<<< orphan*/  flags; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* i2c_gate_ctrl ) (struct dvb_frontend*,int) ;} ;
struct dtv_frontend_properties {int frequency; } ;
struct dvb_frontend {TYPE_2__ ops; TYPE_1__* dvb; struct dtv_frontend_properties dtv_property_cache; } ;
typedef  int /*<<< orphan*/  data ;
struct TYPE_3__ {scalar_t__ priv; } ;

/* Variables and functions */
 int EIO ; 
 int i2c_transfer (int /*<<< orphan*/ *,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  stub1 (struct dvb_frontend*,int) ; 

__attribute__((used)) static int alps_tdmb7_tuner_set_params(struct dvb_frontend *fe)
{
	struct dtv_frontend_properties *p = &fe->dtv_property_cache;
	struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
	u8 data[4];
	struct i2c_msg msg = {.addr=0x61, .flags=0, .buf=data, .len=sizeof(data) };
	u32 div;

	div = (p->frequency + 36166667) / 166667;

	data[0] = (div >> 8) & 0x7f;
	data[1] = div & 0xff;
	data[2] = ((div >> 10) & 0x60) | 0x85;
	data[3] = p->frequency < 592000000 ? 0x40 : 0x80;

	if (fe->ops.i2c_gate_ctrl)
		fe->ops.i2c_gate_ctrl(fe, 1);
	if (i2c_transfer(&ttusb->i2c_adap, &msg, 1) != 1) return -EIO;
	return 0;
}