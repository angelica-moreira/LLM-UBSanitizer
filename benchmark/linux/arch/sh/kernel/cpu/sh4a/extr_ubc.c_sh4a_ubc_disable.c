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
struct arch_hw_breakpoint {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  UBC_CAR (int) ; 
 int /*<<< orphan*/  UBC_CBR (int) ; 
 int /*<<< orphan*/  __raw_writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sh4a_ubc_disable(struct arch_hw_breakpoint *info, int idx)
{
	__raw_writel(0, UBC_CBR(idx));
	__raw_writel(0, UBC_CAR(idx));
}