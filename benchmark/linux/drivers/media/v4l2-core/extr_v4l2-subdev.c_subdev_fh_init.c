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
struct v4l2_subdev_fh {int /*<<< orphan*/ * pad; } ;
struct TYPE_2__ {scalar_t__ num_pads; } ;
struct v4l2_subdev {TYPE_1__ entity; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/ * v4l2_subdev_alloc_pad_config (struct v4l2_subdev*) ; 

__attribute__((used)) static int subdev_fh_init(struct v4l2_subdev_fh *fh, struct v4l2_subdev *sd)
{
#if defined(CONFIG_VIDEO_V4L2_SUBDEV_API)
	if (sd->entity.num_pads) {
		fh->pad = v4l2_subdev_alloc_pad_config(sd);
		if (fh->pad == NULL)
			return -ENOMEM;
	}
#endif
	return 0;
}