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
struct TYPE_2__ {int curr_mode; } ;
struct sd {int bridge; int sensor; TYPE_1__ gspca_dev; int /*<<< orphan*/  sif; } ;
struct cam {void* nmodes; void* cam_mode; } ;
struct gspca_dev {int usb_err; struct cam cam; } ;

/* Variables and functions */
 void* ARRAY_SIZE (void*) ; 
#define  BRIDGE_OV511 148 
#define  BRIDGE_OV511PLUS 147 
#define  BRIDGE_OV518 146 
#define  BRIDGE_OV518PLUS 145 
#define  BRIDGE_OV519 144 
#define  BRIDGE_OVFX2 143 
#define  BRIDGE_W9968CF 142 
 int EINVAL ; 
 int /*<<< orphan*/  OV519_R57_SNAPSHOT ; 
 int /*<<< orphan*/  OV6xx0_SID ; 
 int /*<<< orphan*/  OV7670_COM7_RESET ; 
 int /*<<< orphan*/  OV7670_R12_COM7 ; 
 int /*<<< orphan*/  OV7xx0_SID ; 
 int /*<<< orphan*/  OV8xx0_SID ; 
 int /*<<< orphan*/  OV_HIRES_SID ; 
#define  SEN_OV2610 141 
#define  SEN_OV2610AE 140 
#define  SEN_OV3610 139 
#define  SEN_OV6620 138 
#define  SEN_OV6630 137 
#define  SEN_OV66308AF 136 
#define  SEN_OV7620 135 
#define  SEN_OV7620AE 134 
#define  SEN_OV7640 133 
#define  SEN_OV7648 132 
#define  SEN_OV7660 131 
#define  SEN_OV7670 130 
#define  SEN_OV8610 129 
#define  SEN_OV9600 128 
 int /*<<< orphan*/  gspca_err (struct gspca_dev*,char*) ; 
 int /*<<< orphan*/  i2c_w (struct sd*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_w_mask (struct sd*,int,int,int) ; 
 void* init_519_ov7660 ; 
 scalar_t__ init_ov_sensor (struct sd*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 void* norm_2610 ; 
 void* norm_2610ae ; 
 void* norm_3620b ; 
 void* norm_6x20 ; 
 void* norm_6x30 ; 
 void* norm_7610 ; 
 void* norm_7620 ; 
 void* norm_7640 ; 
 void* norm_7660 ; 
 void* norm_7670 ; 
 void* norm_8610 ; 
 void* norm_9600 ; 
 int /*<<< orphan*/  ov511_configure (struct gspca_dev*) ; 
 void* ov511_sif_mode ; 
 int /*<<< orphan*/  ov518_configure (struct gspca_dev*) ; 
 void* ov518_sif_mode ; 
 int /*<<< orphan*/  ov519_configure (struct sd*) ; 
 int /*<<< orphan*/  ov519_set_fr (struct sd*) ; 
 int /*<<< orphan*/  ov519_set_mode (struct sd*) ; 
 void* ov519_sif_mode ; 
 int /*<<< orphan*/  ov51x_led_control (struct sd*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ov51x_restart (struct sd*) ; 
 int /*<<< orphan*/  ov51x_stop (struct sd*) ; 
 int /*<<< orphan*/  ov6xx0_configure (struct sd*) ; 
 int /*<<< orphan*/  ov7xx0_configure (struct sd*) ; 
 int /*<<< orphan*/  ov8xx0_configure (struct sd*) ; 
 int /*<<< orphan*/  ov_hires_configure (struct sd*) ; 
 int /*<<< orphan*/  ovfx2_configure (struct sd*) ; 
 void* ovfx2_ov2610_mode ; 
 void* ovfx2_ov3610_mode ; 
 void* ovfx2_ov9600_mode ; 
 int /*<<< orphan*/  reg_w (struct sd*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sd_reset_snapshot (struct gspca_dev*) ; 
 int /*<<< orphan*/  w9968cf_configure (struct sd*) ; 
 int /*<<< orphan*/  w9968cf_init (struct sd*) ; 
 void* w9968cf_vga_mode ; 
 int /*<<< orphan*/  write_i2c_regvals (struct sd*,void*,void*) ; 
 int /*<<< orphan*/  write_regvals (struct sd*,void*,void*) ; 

__attribute__((used)) static int sd_init(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;
	struct cam *cam = &gspca_dev->cam;

	switch (sd->bridge) {
	case BRIDGE_OV511:
	case BRIDGE_OV511PLUS:
		ov511_configure(gspca_dev);
		break;
	case BRIDGE_OV518:
	case BRIDGE_OV518PLUS:
		ov518_configure(gspca_dev);
		break;
	case BRIDGE_OV519:
		ov519_configure(sd);
		break;
	case BRIDGE_OVFX2:
		ovfx2_configure(sd);
		break;
	case BRIDGE_W9968CF:
		w9968cf_configure(sd);
		break;
	}

	/* The OV519 must be more aggressive about sensor detection since
	 * I2C write will never fail if the sensor is not present. We have
	 * to try to initialize the sensor to detect its presence */
	sd->sensor = -1;

	/* Test for 76xx */
	if (init_ov_sensor(sd, OV7xx0_SID) >= 0) {
		ov7xx0_configure(sd);

	/* Test for 6xx0 */
	} else if (init_ov_sensor(sd, OV6xx0_SID) >= 0) {
		ov6xx0_configure(sd);

	/* Test for 8xx0 */
	} else if (init_ov_sensor(sd, OV8xx0_SID) >= 0) {
		ov8xx0_configure(sd);

	/* Test for 3xxx / 2xxx */
	} else if (init_ov_sensor(sd, OV_HIRES_SID) >= 0) {
		ov_hires_configure(sd);
	} else {
		gspca_err(gspca_dev, "Can't determine sensor slave IDs\n");
		goto error;
	}

	if (sd->sensor < 0)
		goto error;

	ov51x_led_control(sd, 0);	/* turn LED off */

	switch (sd->bridge) {
	case BRIDGE_OV511:
	case BRIDGE_OV511PLUS:
		if (sd->sif) {
			cam->cam_mode = ov511_sif_mode;
			cam->nmodes = ARRAY_SIZE(ov511_sif_mode);
		}
		break;
	case BRIDGE_OV518:
	case BRIDGE_OV518PLUS:
		if (sd->sif) {
			cam->cam_mode = ov518_sif_mode;
			cam->nmodes = ARRAY_SIZE(ov518_sif_mode);
		}
		break;
	case BRIDGE_OV519:
		if (sd->sif) {
			cam->cam_mode = ov519_sif_mode;
			cam->nmodes = ARRAY_SIZE(ov519_sif_mode);
		}
		break;
	case BRIDGE_OVFX2:
		switch (sd->sensor) {
		case SEN_OV2610:
		case SEN_OV2610AE:
			cam->cam_mode = ovfx2_ov2610_mode;
			cam->nmodes = ARRAY_SIZE(ovfx2_ov2610_mode);
			break;
		case SEN_OV3610:
			cam->cam_mode = ovfx2_ov3610_mode;
			cam->nmodes = ARRAY_SIZE(ovfx2_ov3610_mode);
			break;
		case SEN_OV9600:
			cam->cam_mode = ovfx2_ov9600_mode;
			cam->nmodes = ARRAY_SIZE(ovfx2_ov9600_mode);
			break;
		default:
			if (sd->sif) {
				cam->cam_mode = ov519_sif_mode;
				cam->nmodes = ARRAY_SIZE(ov519_sif_mode);
			}
			break;
		}
		break;
	case BRIDGE_W9968CF:
		if (sd->sif)
			cam->nmodes = ARRAY_SIZE(w9968cf_vga_mode) - 1;

		/* w9968cf needs initialisation once the sensor is known */
		w9968cf_init(sd);
		break;
	}

	/* initialize the sensor */
	switch (sd->sensor) {
	case SEN_OV2610:
		write_i2c_regvals(sd, norm_2610, ARRAY_SIZE(norm_2610));

		/* Enable autogain, autoexpo, awb, bandfilter */
		i2c_w_mask(sd, 0x13, 0x27, 0x27);
		break;
	case SEN_OV2610AE:
		write_i2c_regvals(sd, norm_2610ae, ARRAY_SIZE(norm_2610ae));

		/* enable autoexpo */
		i2c_w_mask(sd, 0x13, 0x05, 0x05);
		break;
	case SEN_OV3610:
		write_i2c_regvals(sd, norm_3620b, ARRAY_SIZE(norm_3620b));

		/* Enable autogain, autoexpo, awb, bandfilter */
		i2c_w_mask(sd, 0x13, 0x27, 0x27);
		break;
	case SEN_OV6620:
		write_i2c_regvals(sd, norm_6x20, ARRAY_SIZE(norm_6x20));
		break;
	case SEN_OV6630:
	case SEN_OV66308AF:
		write_i2c_regvals(sd, norm_6x30, ARRAY_SIZE(norm_6x30));
		break;
	default:
/*	case SEN_OV7610: */
/*	case SEN_OV76BE: */
		write_i2c_regvals(sd, norm_7610, ARRAY_SIZE(norm_7610));
		i2c_w_mask(sd, 0x0e, 0x00, 0x40);
		break;
	case SEN_OV7620:
	case SEN_OV7620AE:
		write_i2c_regvals(sd, norm_7620, ARRAY_SIZE(norm_7620));
		break;
	case SEN_OV7640:
	case SEN_OV7648:
		write_i2c_regvals(sd, norm_7640, ARRAY_SIZE(norm_7640));
		break;
	case SEN_OV7660:
		i2c_w(sd, OV7670_R12_COM7, OV7670_COM7_RESET);
		msleep(14);
		reg_w(sd, OV519_R57_SNAPSHOT, 0x23);
		write_regvals(sd, init_519_ov7660,
				ARRAY_SIZE(init_519_ov7660));
		write_i2c_regvals(sd, norm_7660, ARRAY_SIZE(norm_7660));
		sd->gspca_dev.curr_mode = 1;	/* 640x480 */
		ov519_set_mode(sd);
		ov519_set_fr(sd);
		sd_reset_snapshot(gspca_dev);
		ov51x_restart(sd);
		ov51x_stop(sd);			/* not in win traces */
		ov51x_led_control(sd, 0);
		break;
	case SEN_OV7670:
		write_i2c_regvals(sd, norm_7670, ARRAY_SIZE(norm_7670));
		break;
	case SEN_OV8610:
		write_i2c_regvals(sd, norm_8610, ARRAY_SIZE(norm_8610));
		break;
	case SEN_OV9600:
		write_i2c_regvals(sd, norm_9600, ARRAY_SIZE(norm_9600));

		/* enable autoexpo */
/*		i2c_w_mask(sd, 0x13, 0x05, 0x05); */
		break;
	}
	return gspca_dev->usb_err;
error:
	gspca_err(gspca_dev, "OV519 Config failed\n");
	return -EINVAL;
}