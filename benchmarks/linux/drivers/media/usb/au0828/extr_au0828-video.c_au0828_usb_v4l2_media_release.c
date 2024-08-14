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
struct au0828_dev {int /*<<< orphan*/ * input_ent; } ;
struct TYPE_2__ {scalar_t__ type; } ;

/* Variables and functions */
 int AU0828_MAX_INPUT ; 
 scalar_t__ AU0828_VMUX_UNDEFINED ; 
 TYPE_1__ AUVI_INPUT (int) ; 
 int /*<<< orphan*/  media_device_unregister_entity (int /*<<< orphan*/ *) ; 

void au0828_usb_v4l2_media_release(struct au0828_dev *dev)
{
#ifdef CONFIG_MEDIA_CONTROLLER
	int i;

	for (i = 0; i < AU0828_MAX_INPUT; i++) {
		if (AUVI_INPUT(i).type == AU0828_VMUX_UNDEFINED)
			return;
		media_device_unregister_entity(&dev->input_ent[i]);
	}
#endif
}