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
typedef  enum pr_type { ____Placeholder_pr_type } pr_type ;

/* Variables and functions */
#define  PR_EXCLUSIVE_ACCESS 133 
#define  PR_EXCLUSIVE_ACCESS_ALL_REGS 132 
#define  PR_EXCLUSIVE_ACCESS_REG_ONLY 131 
#define  PR_WRITE_EXCLUSIVE 130 
#define  PR_WRITE_EXCLUSIVE_ALL_REGS 129 
#define  PR_WRITE_EXCLUSIVE_REG_ONLY 128 

__attribute__((used)) static char nvme_pr_type(enum pr_type type)
{
	switch (type) {
	case PR_WRITE_EXCLUSIVE:
		return 1;
	case PR_EXCLUSIVE_ACCESS:
		return 2;
	case PR_WRITE_EXCLUSIVE_REG_ONLY:
		return 3;
	case PR_EXCLUSIVE_ACCESS_REG_ONLY:
		return 4;
	case PR_WRITE_EXCLUSIVE_ALL_REGS:
		return 5;
	case PR_EXCLUSIVE_ACCESS_ALL_REGS:
		return 6;
	default:
		return 0;
	}
}