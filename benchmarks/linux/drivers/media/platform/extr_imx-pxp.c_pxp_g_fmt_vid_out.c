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
 int /*<<< orphan*/  file2ctx (struct file*) ; 
 int pxp_g_fmt (int /*<<< orphan*/ ,struct v4l2_format*) ; 

__attribute__((used)) static int pxp_g_fmt_vid_out(struct file *file, void *priv,
				struct v4l2_format *f)
{
	return pxp_g_fmt(file2ctx(file), f);
}