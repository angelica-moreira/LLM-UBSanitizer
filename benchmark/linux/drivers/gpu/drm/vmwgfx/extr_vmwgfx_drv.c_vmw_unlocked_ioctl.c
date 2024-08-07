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
 int /*<<< orphan*/  drm_ioctl ; 
 long vmw_generic_ioctl (struct file*,unsigned int,unsigned long,int /*<<< orphan*/ *) ; 

__attribute__((used)) static long vmw_unlocked_ioctl(struct file *filp, unsigned int cmd,
			       unsigned long arg)
{
	return vmw_generic_ioctl(filp, cmd, arg, &drm_ioctl);
}