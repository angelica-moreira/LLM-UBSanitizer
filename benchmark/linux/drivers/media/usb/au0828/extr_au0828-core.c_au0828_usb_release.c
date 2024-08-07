#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct au0828_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  au0828_i2c_unregister (struct au0828_dev*) ; 
 int /*<<< orphan*/  au0828_unregister_media_device (struct au0828_dev*) ; 
 int /*<<< orphan*/  kfree (struct au0828_dev*) ; 

void au0828_usb_release(struct au0828_dev *dev)
{
	au0828_unregister_media_device(dev);

	/* I2C */
	au0828_i2c_unregister(dev);

	kfree(dev);
}