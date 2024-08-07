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
 int /*<<< orphan*/  core ; 
 int /*<<< orphan*/  get_v4l2_dev (struct file*) ; 
 int /*<<< orphan*/  ioctl ; 
 long v4l2_device_call_until_err (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,void*) ; 

__attribute__((used)) static long radio_si4713_default(struct file *file, void *p,
				 bool valid_prio, unsigned int cmd, void *arg)
{
	return v4l2_device_call_until_err(get_v4l2_dev(file), 0, core,
					  ioctl, cmd, arg);
}