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
struct esp {scalar_t__ dma_regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  vdma_disable (int) ; 

__attribute__((used)) static void jazz_esp_dma_invalidate(struct esp *esp)
{
	vdma_disable ((int)esp->dma_regs);
}