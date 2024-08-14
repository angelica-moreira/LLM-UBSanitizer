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
struct pvr2_params {int val; char* name; } ;

/* Variables and functions */

__attribute__((used)) static char *pvr2_get_param_name(const struct pvr2_params *p, int val,
			  int size)
{
	int i;

	for (i = 0; i < size; i++) {
		if (p[i].val == val)
			return p[i].name;
	}
	return NULL;
}