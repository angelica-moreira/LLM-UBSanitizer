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
typedef  int u32 ;
struct TYPE_2__ {int x86_stepping; } ;

/* Variables and functions */
 TYPE_1__ boot_cpu_data ; 

__attribute__((used)) static u32 hsx_deadline_rev(void)
{
	switch (boot_cpu_data.x86_stepping) {
	case 0x02: return 0x3a; /* EP */
	case 0x04: return 0x0f; /* EX */
	}

	return ~0U;
}