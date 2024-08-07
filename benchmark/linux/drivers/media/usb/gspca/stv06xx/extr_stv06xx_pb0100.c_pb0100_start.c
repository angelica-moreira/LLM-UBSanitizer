#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct usb_interface {int dummy; } ;
struct usb_host_interface {TYPE_3__* endpoint; } ;
struct cam {TYPE_1__* cam_mode; } ;
struct TYPE_10__ {size_t curr_mode; int /*<<< orphan*/  alt; int /*<<< orphan*/  iface; int /*<<< orphan*/  dev; struct cam cam; } ;
struct sd {TYPE_5__ gspca_dev; TYPE_4__* sensor; } ;
struct gspca_dev {int dummy; } ;
struct TYPE_9__ {int* max_packet_size; } ;
struct TYPE_7__ {int /*<<< orphan*/  wMaxPacketSize; } ;
struct TYPE_8__ {TYPE_2__ desc; } ;
struct TYPE_6__ {int priv; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  D_STREAM ; 
 int ENODEV ; 
 int PB0100_CROP_TO_VGA ; 
 int PB0100_SUBSAMPLE ; 
 int /*<<< orphan*/  PB_CONTROL ; 
 int /*<<< orphan*/  PB_CSTART ; 
 int /*<<< orphan*/  PB_CWSIZE ; 
 int /*<<< orphan*/  PB_ROWSPEED ; 
 int /*<<< orphan*/  PB_RSTART ; 
 int /*<<< orphan*/  PB_RWSIZE ; 
 int /*<<< orphan*/  STV_SCAN_RATE ; 
 int /*<<< orphan*/  STV_X_CTRL ; 
 int /*<<< orphan*/  STV_Y_CTRL ; 
 int /*<<< orphan*/  gspca_dbg (struct gspca_dev*,int /*<<< orphan*/ ,char*,int) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stv06xx_write_bridge (struct sd*,int /*<<< orphan*/ ,int) ; 
 int stv06xx_write_sensor (struct sd*,int /*<<< orphan*/ ,int) ; 
 struct usb_host_interface* usb_altnum_to_altsetting (struct usb_interface*,int /*<<< orphan*/ ) ; 
 struct usb_interface* usb_ifnum_to_if (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int pb0100_start(struct sd *sd)
{
	int err, packet_size, max_packet_size;
	struct usb_host_interface *alt;
	struct usb_interface *intf;
	struct gspca_dev *gspca_dev = (struct gspca_dev *)sd;
	struct cam *cam = &sd->gspca_dev.cam;
	u32 mode = cam->cam_mode[sd->gspca_dev.curr_mode].priv;

	intf = usb_ifnum_to_if(sd->gspca_dev.dev, sd->gspca_dev.iface);
	alt = usb_altnum_to_altsetting(intf, sd->gspca_dev.alt);
	if (!alt)
		return -ENODEV;
	packet_size = le16_to_cpu(alt->endpoint[0].desc.wMaxPacketSize);

	/* If we don't have enough bandwidth use a lower framerate */
	max_packet_size = sd->sensor->max_packet_size[sd->gspca_dev.curr_mode];
	if (packet_size < max_packet_size)
		stv06xx_write_sensor(sd, PB_ROWSPEED, BIT(4)|BIT(3)|BIT(1));
	else
		stv06xx_write_sensor(sd, PB_ROWSPEED, BIT(5)|BIT(3)|BIT(1));

	/* Setup sensor window */
	if (mode & PB0100_CROP_TO_VGA) {
		stv06xx_write_sensor(sd, PB_RSTART, 30);
		stv06xx_write_sensor(sd, PB_CSTART, 20);
		stv06xx_write_sensor(sd, PB_RWSIZE, 240 - 1);
		stv06xx_write_sensor(sd, PB_CWSIZE, 320 - 1);
	} else {
		stv06xx_write_sensor(sd, PB_RSTART, 8);
		stv06xx_write_sensor(sd, PB_CSTART, 4);
		stv06xx_write_sensor(sd, PB_RWSIZE, 288 - 1);
		stv06xx_write_sensor(sd, PB_CWSIZE, 352 - 1);
	}

	if (mode & PB0100_SUBSAMPLE) {
		stv06xx_write_bridge(sd, STV_Y_CTRL, 0x02); /* Wrong, FIXME */
		stv06xx_write_bridge(sd, STV_X_CTRL, 0x06);

		stv06xx_write_bridge(sd, STV_SCAN_RATE, 0x10);
	} else {
		stv06xx_write_bridge(sd, STV_Y_CTRL, 0x01);
		stv06xx_write_bridge(sd, STV_X_CTRL, 0x0a);
		/* larger -> slower */
		stv06xx_write_bridge(sd, STV_SCAN_RATE, 0x20);
	}

	err = stv06xx_write_sensor(sd, PB_CONTROL, BIT(5)|BIT(3)|BIT(1));
	gspca_dbg(gspca_dev, D_STREAM, "Started stream, status: %d\n", err);

	return (err < 0) ? err : 0;
}