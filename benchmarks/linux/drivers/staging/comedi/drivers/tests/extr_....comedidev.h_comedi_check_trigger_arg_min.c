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

/* Variables and functions */
 int EINVAL ; 

__attribute__((used)) static inline int comedi_check_trigger_arg_min(unsigned int *arg,
					       unsigned int val)
{
	if (*arg < val) {
		*arg = val;
		return -EINVAL;
	}
	return 0;
}