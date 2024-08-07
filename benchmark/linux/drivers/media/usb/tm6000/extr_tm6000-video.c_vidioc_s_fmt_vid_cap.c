#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  pixelformat; int /*<<< orphan*/  field; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct TYPE_6__ {TYPE_2__ pix; } ;
struct v4l2_format {TYPE_3__ fmt; int /*<<< orphan*/  type; } ;
struct TYPE_4__ {int /*<<< orphan*/  field; } ;
struct tm6000_fh {int /*<<< orphan*/  type; TYPE_1__ vb_vidq; int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  fmt; struct tm6000_core* dev; } ;
struct tm6000_core {int /*<<< orphan*/  fourcc; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  format_by_fourcc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tm6000_set_fourcc_format (struct tm6000_core*) ; 
 int vidioc_try_fmt_vid_cap (struct file*,struct tm6000_fh*,struct v4l2_format*) ; 

__attribute__((used)) static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
					struct v4l2_format *f)
{
	struct tm6000_fh  *fh = priv;
	struct tm6000_core *dev = fh->dev;
	int ret = vidioc_try_fmt_vid_cap(file, fh, f);
	if (ret < 0)
		return ret;

	fh->fmt           = format_by_fourcc(f->fmt.pix.pixelformat);
	fh->width         = f->fmt.pix.width;
	fh->height        = f->fmt.pix.height;
	fh->vb_vidq.field = f->fmt.pix.field;
	fh->type          = f->type;

	dev->fourcc       = f->fmt.pix.pixelformat;

	tm6000_set_fourcc_format(dev);

	return 0;
}