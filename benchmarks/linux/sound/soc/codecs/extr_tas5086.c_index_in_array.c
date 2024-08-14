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
 int ENOENT ; 

__attribute__((used)) static int index_in_array(const int *array, int len, int needle)
{
	int i;

	for (i = 0; i < len; i++)
		if (array[i] == needle)
			return i;

	return -ENOENT;
}