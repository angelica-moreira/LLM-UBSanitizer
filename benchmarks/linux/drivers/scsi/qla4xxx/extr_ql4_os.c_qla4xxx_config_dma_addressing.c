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
struct scsi_qla_host {TYPE_1__* pdev; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ dma_set_mask_and_coherent (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void qla4xxx_config_dma_addressing(struct scsi_qla_host *ha)
{
	/* Update our PCI device dma_mask for full 64 bit mask */
	if (dma_set_mask_and_coherent(&ha->pdev->dev, DMA_BIT_MASK(64))) {
		dev_dbg(&ha->pdev->dev,
			  "Failed to set 64 bit PCI consistent mask; "
			   "using 32 bit.\n");
		dma_set_mask_and_coherent(&ha->pdev->dev, DMA_BIT_MASK(32));
	}
}