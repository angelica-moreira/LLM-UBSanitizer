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
struct file {int dummy; } ;

/* Variables and functions */
 int cxusb_medion_try_s_fmt_vid_cap (struct file*,struct v4l2_format*,int) ; 

__attribute__((used)) static int cxusb_medion_try_fmt_vid_cap(struct file *file, void *fh,
					struct v4l2_format *f)
{
	return cxusb_medion_try_s_fmt_vid_cap(file, f, false);
}