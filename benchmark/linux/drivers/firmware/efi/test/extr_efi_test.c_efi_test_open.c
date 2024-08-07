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
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int EACCES ; 
 int /*<<< orphan*/  LOCKDOWN_EFI_TEST ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 int security_locked_down (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int efi_test_open(struct inode *inode, struct file *file)
{
	int ret = security_locked_down(LOCKDOWN_EFI_TEST);

	if (ret)
		return ret;

	if (!capable(CAP_SYS_ADMIN))
		return -EACCES;
	/*
	 * nothing special to do here
	 * We do accept multiple open files at the same time as we
	 * synchronize on the per call operation.
	 */
	return 0;
}