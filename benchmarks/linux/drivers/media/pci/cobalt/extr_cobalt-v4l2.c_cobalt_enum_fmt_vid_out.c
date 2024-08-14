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
struct v4l2_fmtdesc {int index; int /*<<< orphan*/  pixelformat; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  V4L2_PIX_FMT_BGR32 ; 
 int /*<<< orphan*/  V4L2_PIX_FMT_YUYV ; 

__attribute__((used)) static int cobalt_enum_fmt_vid_out(struct file *file, void *priv_fh,
		struct v4l2_fmtdesc *f)
{
	switch (f->index) {
	case 0:
		f->pixelformat = V4L2_PIX_FMT_YUYV;
		break;
	case 1:
		f->pixelformat = V4L2_PIX_FMT_BGR32;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}