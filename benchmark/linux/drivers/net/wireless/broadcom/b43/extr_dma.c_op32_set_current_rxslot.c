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
typedef  int /*<<< orphan*/  u32 ;
struct b43_dmaring {int dummy; } ;
struct b43_dmadesc32 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43_DMA32_RXINDEX ; 
 int /*<<< orphan*/  b43_dma_write (struct b43_dmaring*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void op32_set_current_rxslot(struct b43_dmaring *ring, int slot)
{
	b43_dma_write(ring, B43_DMA32_RXINDEX,
		      (u32) (slot * sizeof(struct b43_dmadesc32)));
}