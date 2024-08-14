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
struct TYPE_4__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct TYPE_3__ {TYPE_2__ pixfmt; } ;
struct sd {int bridge; int snapshot_needs_reset; int first_frame; TYPE_1__ gspca_dev; int /*<<< orphan*/  sensor_height; int /*<<< orphan*/  sensor_width; } ;
struct gspca_dev {int usb_err; } ;

/* Variables and functions */
#define  BRIDGE_OV511 133 
#define  BRIDGE_OV511PLUS 132 
#define  BRIDGE_OV518 131 
#define  BRIDGE_OV518PLUS 130 
#define  BRIDGE_OV519 129 
#define  BRIDGE_W9968CF 128 
 int /*<<< orphan*/  ov511_mode_init_regs (struct sd*) ; 
 int /*<<< orphan*/  ov518_mode_init_regs (struct sd*) ; 
 int /*<<< orphan*/  ov519_mode_init_regs (struct sd*) ; 
 int /*<<< orphan*/  ov51x_led_control (struct sd*,int) ; 
 int /*<<< orphan*/  ov51x_restart (struct sd*) ; 
 int /*<<< orphan*/  sd_reset_snapshot (struct gspca_dev*) ; 
 int /*<<< orphan*/  set_ov_sensor_window (struct sd*) ; 
 int /*<<< orphan*/  w9968cf_mode_init_regs (struct sd*) ; 

__attribute__((used)) static int sd_start(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	/* Default for most bridges, allow bridge_mode_init_regs to override */
	sd->sensor_width = sd->gspca_dev.pixfmt.width;
	sd->sensor_height = sd->gspca_dev.pixfmt.height;

	switch (sd->bridge) {
	case BRIDGE_OV511:
	case BRIDGE_OV511PLUS:
		ov511_mode_init_regs(sd);
		break;
	case BRIDGE_OV518:
	case BRIDGE_OV518PLUS:
		ov518_mode_init_regs(sd);
		break;
	case BRIDGE_OV519:
		ov519_mode_init_regs(sd);
		break;
	/* case BRIDGE_OVFX2: nothing to do */
	case BRIDGE_W9968CF:
		w9968cf_mode_init_regs(sd);
		break;
	}

	set_ov_sensor_window(sd);

	/* Force clear snapshot state in case the snapshot button was
	   pressed while we weren't streaming */
	sd->snapshot_needs_reset = 1;
	sd_reset_snapshot(gspca_dev);

	sd->first_frame = 3;

	ov51x_restart(sd);
	ov51x_led_control(sd, 1);
	return gspca_dev->usb_err;
}