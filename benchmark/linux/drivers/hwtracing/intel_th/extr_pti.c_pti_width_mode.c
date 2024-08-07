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
 int ARRAY_SIZE (unsigned int*) ; 
 int EINVAL ; 
 unsigned int* pti_mode ; 

__attribute__((used)) static int pti_width_mode(unsigned int width)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(pti_mode); i++)
		if (pti_mode[i] == width)
			return i;

	return -EINVAL;
}