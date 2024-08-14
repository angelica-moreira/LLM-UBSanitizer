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
typedef  scalar_t__ dma_addr_t ;
struct TYPE_2__ {scalar_t__ regs; scalar_t__ lp_tx_addr; } ;

/* Variables and functions */
 scalar_t__ I2STRNCNT ; 
 TYPE_1__ idma ; 
 int readl (scalar_t__) ; 

__attribute__((used)) static void idma_getpos(dma_addr_t *src)
{
	*src = idma.lp_tx_addr +
		(readl(idma.regs + I2STRNCNT) & 0xffffff) * 4;
}