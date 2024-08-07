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
struct TYPE_2__ {int /*<<< orphan*/  win; } ;
struct v4l2_format {TYPE_1__ fmt; } ;
struct file {int dummy; } ;
struct bm2835_mmal_dev {int /*<<< orphan*/  overlay; } ;

/* Variables and functions */
 struct bm2835_mmal_dev* video_drvdata (struct file*) ; 

__attribute__((used)) static int vidioc_g_fmt_vid_overlay(struct file *file, void *priv,
				    struct v4l2_format *f)
{
	struct bm2835_mmal_dev *dev = video_drvdata(file);

	f->fmt.win = dev->overlay;

	return 0;
}