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
 int /*<<< orphan*/  PRCM_A9_MASK_REQ ; 
 int PRCM_A9_MASK_REQ_PRCM_A9_MASK_REQ ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

int prcmu_gic_recouple(void)
{
	u32 val = readl(PRCM_A9_MASK_REQ);

	/* Set bit 0 register value to 0 */
	writel(val & ~PRCM_A9_MASK_REQ_PRCM_A9_MASK_REQ, PRCM_A9_MASK_REQ);

	return 0;
}