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
typedef  int /*<<< orphan*/  u8 ;
struct tveeprom {int model; } ;
struct i2c_client {int addr; int /*<<< orphan*/ * adapter; int /*<<< orphan*/  name; } ;
struct cx18 {TYPE_1__* card; int /*<<< orphan*/ * i2c_adap; } ;
typedef  int /*<<< orphan*/  eedata ;
struct TYPE_2__ {int type; } ;

/* Variables and functions */
#define  CX18_CARD_GOTVIEW_PCI_DVD3 132 
#define  CX18_CARD_HVR_1600_ESMT 131 
#define  CX18_CARD_HVR_1600_S5H1411 130 
#define  CX18_CARD_HVR_1600_SAMSUNG 129 
#define  CX18_CARD_YUAN_MPC718 128 
 int /*<<< orphan*/  CX18_INFO (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  cx18_eeprom_dump (struct cx18*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  kfree (struct i2c_client*) ; 
 struct i2c_client* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct tveeprom*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strscpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  tveeprom_hauppauge_analog (struct tveeprom*,int /*<<< orphan*/ *) ; 
 scalar_t__ tveeprom_read (struct i2c_client*,int /*<<< orphan*/ *,int) ; 

void cx18_read_eeprom(struct cx18 *cx, struct tveeprom *tv)
{
	struct i2c_client *c;
	u8 eedata[256];

	memset(tv, 0, sizeof(*tv));

	c = kzalloc(sizeof(*c), GFP_KERNEL);
	if (!c)
		return;

	strscpy(c->name, "cx18 tveeprom tmp", sizeof(c->name));
	c->adapter = &cx->i2c_adap[0];
	c->addr = 0xa0 >> 1;

	if (tveeprom_read(c, eedata, sizeof(eedata)))
		goto ret;

	switch (cx->card->type) {
	case CX18_CARD_HVR_1600_ESMT:
	case CX18_CARD_HVR_1600_SAMSUNG:
	case CX18_CARD_HVR_1600_S5H1411:
		tveeprom_hauppauge_analog(tv, eedata);
		break;
	case CX18_CARD_YUAN_MPC718:
	case CX18_CARD_GOTVIEW_PCI_DVD3:
		tv->model = 0x718;
		cx18_eeprom_dump(cx, eedata, sizeof(eedata));
		CX18_INFO("eeprom PCI ID: %02x%02x:%02x%02x\n",
			  eedata[2], eedata[1], eedata[4], eedata[3]);
		break;
	default:
		tv->model = 0xffffffff;
		cx18_eeprom_dump(cx, eedata, sizeof(eedata));
		break;
	}

ret:
	kfree(c);
}