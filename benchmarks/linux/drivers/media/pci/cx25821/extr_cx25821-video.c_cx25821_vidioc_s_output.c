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
struct file {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 

__attribute__((used)) static int cx25821_vidioc_s_output(struct file *file, void *priv, unsigned int o)
{
	return o ? -EINVAL : 0;
}