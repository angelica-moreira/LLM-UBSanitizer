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
 int call_int_hook (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct file*,unsigned int,unsigned long) ; 
 int /*<<< orphan*/  file_ioctl ; 

int security_file_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	return call_int_hook(file_ioctl, 0, file, cmd, arg);
}