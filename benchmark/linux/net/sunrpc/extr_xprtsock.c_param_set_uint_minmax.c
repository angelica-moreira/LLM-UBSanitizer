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
struct kernel_param {scalar_t__ arg; } ;

/* Variables and functions */
 int EINVAL ; 
 int kstrtouint (char const*,int /*<<< orphan*/ ,unsigned int*) ; 

__attribute__((used)) static int param_set_uint_minmax(const char *val,
		const struct kernel_param *kp,
		unsigned int min, unsigned int max)
{
	unsigned int num;
	int ret;

	if (!val)
		return -EINVAL;
	ret = kstrtouint(val, 0, &num);
	if (ret)
		return ret;
	if (num < min || num > max)
		return -EINVAL;
	*((unsigned int *)kp->arg) = num;
	return 0;
}