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
struct v4l2_tuner {scalar_t__ index; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 

int saa7164_s_tuner(struct file *file, void *priv,
			   const struct v4l2_tuner *t)
{
	if (0 != t->index)
		return -EINVAL;

	/* Update the A/V core */
	return 0;
}