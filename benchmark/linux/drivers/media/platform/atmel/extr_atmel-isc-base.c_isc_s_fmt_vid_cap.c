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
struct v4l2_format {int dummy; } ;
struct isc_device {int /*<<< orphan*/  vb2_vidq; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int EBUSY ; 
 int isc_set_fmt (struct isc_device*,struct v4l2_format*) ; 
 scalar_t__ vb2_is_streaming (int /*<<< orphan*/ *) ; 
 struct isc_device* video_drvdata (struct file*) ; 

__attribute__((used)) static int isc_s_fmt_vid_cap(struct file *file, void *priv,
			      struct v4l2_format *f)
{
	struct isc_device *isc = video_drvdata(file);

	if (vb2_is_streaming(&isc->vb2_vidq))
		return -EBUSY;

	return isc_set_fmt(isc, f);
}