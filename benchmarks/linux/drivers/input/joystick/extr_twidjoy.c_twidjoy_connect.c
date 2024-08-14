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
struct twidjoy_button_spec {int bitmask; int /*<<< orphan*/ * buttons; } ;
struct twidjoy {struct input_dev* dev; int /*<<< orphan*/  phys; } ;
struct serio_driver {int dummy; } ;
struct serio {char* phys; int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {int product; int version; int /*<<< orphan*/  vendor; int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; int* evbit; int /*<<< orphan*/  keybit; TYPE_2__ dev; TYPE_1__ id; int /*<<< orphan*/  phys; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int BIT_MASK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUS_RS232 ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  SERIO_TWIDJOY ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int,int,int,int) ; 
 int /*<<< orphan*/  kfree (struct twidjoy*) ; 
 struct twidjoy* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_close (struct serio*) ; 
 int serio_open (struct serio*,struct serio_driver*) ; 
 int /*<<< orphan*/  serio_set_drvdata (struct serio*,struct twidjoy*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 struct twidjoy_button_spec* twidjoy_buttons ; 

__attribute__((used)) static int twidjoy_connect(struct serio *serio, struct serio_driver *drv)
{
	struct twidjoy_button_spec *bp;
	struct twidjoy *twidjoy;
	struct input_dev *input_dev;
	int err = -ENOMEM;
	int i;

	twidjoy = kzalloc(sizeof(struct twidjoy), GFP_KERNEL);
	input_dev = input_allocate_device();
	if (!twidjoy || !input_dev)
		goto fail1;

	twidjoy->dev = input_dev;
	snprintf(twidjoy->phys, sizeof(twidjoy->phys), "%s/input0", serio->phys);

	input_dev->name = "Handykey Twiddler";
	input_dev->phys = twidjoy->phys;
	input_dev->id.bustype = BUS_RS232;
	input_dev->id.vendor = SERIO_TWIDJOY;
	input_dev->id.product = 0x0001;
	input_dev->id.version = 0x0100;
	input_dev->dev.parent = &serio->dev;

	input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
	input_set_abs_params(input_dev, ABS_X, -50, 50, 4, 4);
	input_set_abs_params(input_dev, ABS_Y, -50, 50, 4, 4);

	for (bp = twidjoy_buttons; bp->bitmask; bp++)
		for (i = 0; i < bp->bitmask; i++)
			set_bit(bp->buttons[i], input_dev->keybit);

	serio_set_drvdata(serio, twidjoy);

	err = serio_open(serio, drv);
	if (err)
		goto fail2;

	err = input_register_device(twidjoy->dev);
	if (err)
		goto fail3;

	return 0;

 fail3:	serio_close(serio);
 fail2:	serio_set_drvdata(serio, NULL);
 fail1:	input_free_device(input_dev);
	kfree(twidjoy);
	return err;
}