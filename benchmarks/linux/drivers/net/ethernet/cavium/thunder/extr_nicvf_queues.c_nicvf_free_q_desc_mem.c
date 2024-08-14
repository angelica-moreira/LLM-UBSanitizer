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
struct q_desc_mem {int /*<<< orphan*/ * base; int /*<<< orphan*/ * unalign_base; int /*<<< orphan*/  dma; int /*<<< orphan*/  size; } ;
struct nicvf {TYPE_1__* pdev; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nicvf_free_q_desc_mem(struct nicvf *nic, struct q_desc_mem *dmem)
{
	if (!dmem)
		return;

	dma_free_coherent(&nic->pdev->dev, dmem->size,
			  dmem->unalign_base, dmem->dma);
	dmem->unalign_base = NULL;
	dmem->base = NULL;
}