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
struct sis7019 {int /*<<< orphan*/  silence_dma_addr; TYPE_1__* pci; int /*<<< orphan*/  silence_users; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_TO_DEVICE ; 
 int /*<<< orphan*/  dma_unmap_single (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void __sis_unmap_silence(struct sis7019 *sis)
{
	/* Helper function: must hold sis->voice_lock on entry */
	sis->silence_users--;
	if (!sis->silence_users)
		dma_unmap_single(&sis->pci->dev, sis->silence_dma_addr, 4096,
					DMA_TO_DEVICE);
}