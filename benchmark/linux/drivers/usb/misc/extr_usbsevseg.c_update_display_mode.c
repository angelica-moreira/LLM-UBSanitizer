#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct usb_sevsegdev {int shadow_power; int mode_msb; TYPE_1__* udev; scalar_t__ mode_lsb; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int) ; 
 int usb_control_msg (TYPE_1__*,int /*<<< orphan*/ ,int,int,int,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void update_display_mode(struct usb_sevsegdev *mydev)
{
	int rc;

	if(mydev->shadow_power != 1)
		return;

	rc = usb_control_msg(mydev->udev,
			usb_sndctrlpipe(mydev->udev, 0),
			0x12,
			0x48,
			(82 * 0x100) + 10, /* (set mode) */
			(mydev->mode_msb * 0x100) + mydev->mode_lsb,
			NULL,
			0,
			2000);

	if (rc < 0)
		dev_dbg(&mydev->udev->dev, "mode retval = %d\n", rc);
}