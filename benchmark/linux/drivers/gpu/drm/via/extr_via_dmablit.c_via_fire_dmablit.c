#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct drm_device {scalar_t__ dev_private; } ;
struct TYPE_3__ {int chain_start; } ;
typedef  TYPE_1__ drm_via_sg_info_t ;
typedef  int /*<<< orphan*/  drm_via_private_t ;

/* Variables and functions */
 int VIA_DMA_CSR_DD ; 
 int VIA_DMA_CSR_DE ; 
 int VIA_DMA_CSR_TD ; 
 int VIA_DMA_CSR_TS ; 
 int VIA_DMA_MR_CM ; 
 int VIA_DMA_MR_TDIE ; 
 scalar_t__ VIA_PCI_DMA_BCR0 ; 
 scalar_t__ VIA_PCI_DMA_CSR0 ; 
 scalar_t__ VIA_PCI_DMA_DAR0 ; 
 scalar_t__ VIA_PCI_DMA_DPR0 ; 
 scalar_t__ VIA_PCI_DMA_MAR0 ; 
 scalar_t__ VIA_PCI_DMA_MR0 ; 
 int /*<<< orphan*/  via_read (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  via_write (int /*<<< orphan*/ *,scalar_t__,int) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static void
via_fire_dmablit(struct drm_device *dev, drm_via_sg_info_t *vsg, int engine)
{
	drm_via_private_t *dev_priv = (drm_via_private_t *)dev->dev_private;

	via_write(dev_priv, VIA_PCI_DMA_MAR0 + engine*0x10, 0);
	via_write(dev_priv, VIA_PCI_DMA_DAR0 + engine*0x10, 0);
	via_write(dev_priv, VIA_PCI_DMA_CSR0 + engine*0x04, VIA_DMA_CSR_DD | VIA_DMA_CSR_TD |
		  VIA_DMA_CSR_DE);
	via_write(dev_priv, VIA_PCI_DMA_MR0  + engine*0x04, VIA_DMA_MR_CM | VIA_DMA_MR_TDIE);
	via_write(dev_priv, VIA_PCI_DMA_BCR0 + engine*0x10, 0);
	via_write(dev_priv, VIA_PCI_DMA_DPR0 + engine*0x10, vsg->chain_start);
	wmb();
	via_write(dev_priv, VIA_PCI_DMA_CSR0 + engine*0x04, VIA_DMA_CSR_DE | VIA_DMA_CSR_TS);
	via_read(dev_priv, VIA_PCI_DMA_CSR0 + engine*0x04);
}