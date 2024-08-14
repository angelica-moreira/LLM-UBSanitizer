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
struct vivid_fmt {int /*<<< orphan*/  fourcc; } ;
struct vivid_dev {scalar_t__ multiplanar; } ;
struct v4l2_fmtdesc {size_t index; int /*<<< orphan*/  pixelformat; } ;
struct file {int dummy; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (struct vivid_fmt*) ; 
 int EINVAL ; 
 int ENOTTY ; 
 struct vivid_fmt* formats_ovl ; 
 struct vivid_dev* video_drvdata (struct file*) ; 

int vidioc_enum_fmt_vid_overlay(struct file *file, void  *priv,
					struct v4l2_fmtdesc *f)
{
	struct vivid_dev *dev = video_drvdata(file);
	const struct vivid_fmt *fmt;

	if (dev->multiplanar)
		return -ENOTTY;

	if (f->index >= ARRAY_SIZE(formats_ovl))
		return -EINVAL;

	fmt = &formats_ovl[f->index];

	f->pixelformat = fmt->fourcc;
	return 0;
}