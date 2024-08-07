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
struct v4l2_ctrl_handler {int error; } ;
struct TYPE_2__ {struct v4l2_ctrl_handler* ctrl_handler; } ;
struct gspca_dev {TYPE_1__ vdev; struct v4l2_ctrl_handler ctrl_handler; } ;

/* Variables and functions */
 int /*<<< orphan*/  V4L2_CID_BRIGHTNESS ; 
 int /*<<< orphan*/  V4L2_CID_CONTRAST ; 
 int /*<<< orphan*/  V4L2_CID_HUE ; 
 int /*<<< orphan*/  V4L2_CID_SATURATION ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  sd_ctrl_ops ; 
 int /*<<< orphan*/  v4l2_ctrl_handler_init (struct v4l2_ctrl_handler*,int) ; 
 int /*<<< orphan*/  v4l2_ctrl_new_std (struct v4l2_ctrl_handler*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int) ; 

__attribute__((used)) static int sd_init_controls(struct gspca_dev *gspca_dev)
{
	struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;

	gspca_dev->vdev.ctrl_handler = hdl;
	v4l2_ctrl_handler_init(hdl, 4);
	v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
			V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
	v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
			V4L2_CID_CONTRAST, 0, 255, 1, 0x47);
	v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
			V4L2_CID_SATURATION, 0, 255, 1, 0x40);
	v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
			V4L2_CID_HUE, 0, 255, 1, 0);

	if (hdl->error) {
		pr_err("Could not initialize controls\n");
		return hdl->error;
	}
	return 0;
}