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
struct v4l2_subdev_pad_config {int dummy; } ;
struct v4l2_subdev_mbus_code_enum {scalar_t__ pad; int index; int /*<<< orphan*/  code; } ;
struct v4l2_subdev {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  MEDIA_BUS_FMT_RGB888_1X24 ; 
 int /*<<< orphan*/  MEDIA_BUS_FMT_UYVY8_1X16 ; 
 int /*<<< orphan*/  MEDIA_BUS_FMT_YUYV8_1X16 ; 

__attribute__((used)) static int adv7511_enum_mbus_code(struct v4l2_subdev *sd,
				  struct v4l2_subdev_pad_config *cfg,
				  struct v4l2_subdev_mbus_code_enum *code)
{
	if (code->pad != 0)
		return -EINVAL;

	switch (code->index) {
	case 0:
		code->code = MEDIA_BUS_FMT_RGB888_1X24;
		break;
	case 1:
		code->code = MEDIA_BUS_FMT_YUYV8_1X16;
		break;
	case 2:
		code->code = MEDIA_BUS_FMT_UYVY8_1X16;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}