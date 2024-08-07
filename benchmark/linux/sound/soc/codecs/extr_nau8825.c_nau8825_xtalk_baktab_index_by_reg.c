#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {unsigned int reg; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 TYPE_1__* nau8825_xtalk_baktab ; 

__attribute__((used)) static int nau8825_xtalk_baktab_index_by_reg(unsigned int reg)
{
	int index;

	for (index = 0; index < ARRAY_SIZE(nau8825_xtalk_baktab); index++)
		if (nau8825_xtalk_baktab[index].reg == reg)
			return index;
	return -EINVAL;
}