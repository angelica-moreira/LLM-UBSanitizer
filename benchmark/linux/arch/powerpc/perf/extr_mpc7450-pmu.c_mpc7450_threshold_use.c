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
typedef  int u32 ;

/* Variables and functions */
 int PM_PMCSEL_MSK ; 
 int PM_PMC_MSK ; 
 int PM_PMC_SH ; 

__attribute__((used)) static int mpc7450_threshold_use(u32 event)
{
	int pmc, sel;

	pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
	sel = event & PM_PMCSEL_MSK;
	switch (pmc) {
	case 1:
		if (sel == 0x1e || sel == 0x1f)
			return 1;
		if (sel == 0x28 || sel == 0x2b)
			return 2;
		break;
	case 2:
		if (sel == 0x20)
			return 1;
		break;
	case 3:
		if (sel == 0xc || sel == 0xd)
			return 1;
		if (sel == 0x11)
			return 2;
		break;
	case 4:
		if (sel == 0x10)
			return 1;
		break;
	}
	return 0;
}