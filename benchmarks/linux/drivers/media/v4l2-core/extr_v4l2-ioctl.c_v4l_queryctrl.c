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
struct video_device {scalar_t__ ctrl_handler; int /*<<< orphan*/  flags; } ;
struct v4l2_queryctrl {int dummy; } ;
struct v4l2_ioctl_ops {int (* vidioc_queryctrl ) (struct file*,void*,struct v4l2_queryctrl*) ;} ;
struct v4l2_fh {scalar_t__ ctrl_handler; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int ENOTTY ; 
 int /*<<< orphan*/  V4L2_FL_USES_V4L2_FH ; 
 int stub1 (struct file*,void*,struct v4l2_queryctrl*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int v4l2_queryctrl (scalar_t__,struct v4l2_queryctrl*) ; 
 struct video_device* video_devdata (struct file*) ; 

__attribute__((used)) static int v4l_queryctrl(const struct v4l2_ioctl_ops *ops,
				struct file *file, void *fh, void *arg)
{
	struct video_device *vfd = video_devdata(file);
	struct v4l2_queryctrl *p = arg;
	struct v4l2_fh *vfh =
		test_bit(V4L2_FL_USES_V4L2_FH, &vfd->flags) ? fh : NULL;

	if (vfh && vfh->ctrl_handler)
		return v4l2_queryctrl(vfh->ctrl_handler, p);
	if (vfd->ctrl_handler)
		return v4l2_queryctrl(vfd->ctrl_handler, p);
	if (ops->vidioc_queryctrl)
		return ops->vidioc_queryctrl(file, fh, p);
	return -ENOTTY;
}