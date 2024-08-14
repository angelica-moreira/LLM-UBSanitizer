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
 scalar_t__ dma_regs ; 
 int /*<<< orphan*/  out_le32 (scalar_t__,unsigned int) ; 

void pasemi_write_dma_reg(unsigned int reg, unsigned int val)
{
	out_le32(dma_regs+reg, val);
}