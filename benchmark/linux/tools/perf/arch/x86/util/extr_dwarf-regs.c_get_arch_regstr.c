#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {char const* name; } ;

/* Variables and functions */
 unsigned int ARCH_MAX_REGS ; 
 TYPE_1__* regoffset_table ; 

const char *get_arch_regstr(unsigned int n)
{
	return (n < ARCH_MAX_REGS) ? regoffset_table[n].name : NULL;
}