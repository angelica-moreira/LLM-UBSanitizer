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
 scalar_t__ twl_class_is_4030 () ; 

__attribute__((used)) static inline int twl_get_num_slaves(void)
{
	if (twl_class_is_4030())
		return 4; /* TWL4030 class have four slave address */
	else
		return 3; /* TWL6030 class have three slave address */
}