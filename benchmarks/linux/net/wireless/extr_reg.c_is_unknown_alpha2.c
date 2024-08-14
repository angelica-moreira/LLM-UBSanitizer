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

__attribute__((used)) static bool is_unknown_alpha2(const char *alpha2)
{
	if (!alpha2)
		return false;
	/*
	 * Special case where regulatory domain was built by driver
	 * but a specific alpha2 cannot be determined
	 */
	return alpha2[0] == '9' && alpha2[1] == '9';
}