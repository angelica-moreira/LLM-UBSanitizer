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

__attribute__((used)) static int get_le_offset(int offset)
{
	int closest_multiple_of_4;

	closest_multiple_of_4 = (offset / 4) * 4;
	offset -= closest_multiple_of_4;
	return closest_multiple_of_4 + (3 - offset);
}