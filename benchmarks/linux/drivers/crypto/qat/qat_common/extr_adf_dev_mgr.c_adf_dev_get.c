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
struct adf_accel_dev {int /*<<< orphan*/  owner; int /*<<< orphan*/  ref_count; } ;

/* Variables and functions */
 int EFAULT ; 
 int atomic_add_return (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  try_module_get (int /*<<< orphan*/ ) ; 

int adf_dev_get(struct adf_accel_dev *accel_dev)
{
	if (atomic_add_return(1, &accel_dev->ref_count) == 1)
		if (!try_module_get(accel_dev->owner))
			return -EFAULT;
	return 0;
}