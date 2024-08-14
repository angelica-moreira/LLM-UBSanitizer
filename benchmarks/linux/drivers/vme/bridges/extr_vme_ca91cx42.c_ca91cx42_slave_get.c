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
typedef  scalar_t__ u32 ;
struct vme_slave_resource {unsigned int number; TYPE_1__* parent; } ;
struct ca91cx42_driver {scalar_t__ base; } ;
typedef  scalar_t__ dma_addr_t ;
struct TYPE_2__ {struct ca91cx42_driver* driver_priv; } ;

/* Variables and functions */
 scalar_t__* CA91CX42_VSI_BD ; 
 scalar_t__* CA91CX42_VSI_BS ; 
 scalar_t__* CA91CX42_VSI_CTL ; 
 unsigned int CA91CX42_VSI_CTL_EN ; 
 unsigned int CA91CX42_VSI_CTL_PGM_DATA ; 
 unsigned int CA91CX42_VSI_CTL_PGM_PGM ; 
 unsigned int CA91CX42_VSI_CTL_SUPER_NPRIV ; 
 unsigned int CA91CX42_VSI_CTL_SUPER_SUPR ; 
 unsigned int CA91CX42_VSI_CTL_VAS_A16 ; 
 unsigned int CA91CX42_VSI_CTL_VAS_A24 ; 
 unsigned int CA91CX42_VSI_CTL_VAS_A32 ; 
 unsigned int CA91CX42_VSI_CTL_VAS_M ; 
 unsigned int CA91CX42_VSI_CTL_VAS_USER1 ; 
 unsigned int CA91CX42_VSI_CTL_VAS_USER2 ; 
 scalar_t__* CA91CX42_VSI_TO ; 
 scalar_t__ VME_A16 ; 
 scalar_t__ VME_A24 ; 
 scalar_t__ VME_A32 ; 
 scalar_t__ VME_DATA ; 
 scalar_t__ VME_PROG ; 
 scalar_t__ VME_SUPER ; 
 scalar_t__ VME_USER ; 
 scalar_t__ VME_USER1 ; 
 scalar_t__ VME_USER2 ; 
 void* ioread32 (scalar_t__) ; 

__attribute__((used)) static int ca91cx42_slave_get(struct vme_slave_resource *image, int *enabled,
	unsigned long long *vme_base, unsigned long long *size,
	dma_addr_t *pci_base, u32 *aspace, u32 *cycle)
{
	unsigned int i, granularity = 0, ctl = 0;
	unsigned long long vme_bound, pci_offset;
	struct ca91cx42_driver *bridge;

	bridge = image->parent->driver_priv;

	i = image->number;

	if ((i == 0) || (i == 4))
		granularity = 0x1000;
	else
		granularity = 0x10000;

	/* Read Registers */
	ctl = ioread32(bridge->base + CA91CX42_VSI_CTL[i]);

	*vme_base = ioread32(bridge->base + CA91CX42_VSI_BS[i]);
	vme_bound = ioread32(bridge->base + CA91CX42_VSI_BD[i]);
	pci_offset = ioread32(bridge->base + CA91CX42_VSI_TO[i]);

	*pci_base = (dma_addr_t)*vme_base + pci_offset;
	*size = (unsigned long long)((vme_bound - *vme_base) + granularity);

	*enabled = 0;
	*aspace = 0;
	*cycle = 0;

	if (ctl & CA91CX42_VSI_CTL_EN)
		*enabled = 1;

	if ((ctl & CA91CX42_VSI_CTL_VAS_M) == CA91CX42_VSI_CTL_VAS_A16)
		*aspace = VME_A16;
	if ((ctl & CA91CX42_VSI_CTL_VAS_M) == CA91CX42_VSI_CTL_VAS_A24)
		*aspace = VME_A24;
	if ((ctl & CA91CX42_VSI_CTL_VAS_M) == CA91CX42_VSI_CTL_VAS_A32)
		*aspace = VME_A32;
	if ((ctl & CA91CX42_VSI_CTL_VAS_M) == CA91CX42_VSI_CTL_VAS_USER1)
		*aspace = VME_USER1;
	if ((ctl & CA91CX42_VSI_CTL_VAS_M) == CA91CX42_VSI_CTL_VAS_USER2)
		*aspace = VME_USER2;

	if (ctl & CA91CX42_VSI_CTL_SUPER_SUPR)
		*cycle |= VME_SUPER;
	if (ctl & CA91CX42_VSI_CTL_SUPER_NPRIV)
		*cycle |= VME_USER;
	if (ctl & CA91CX42_VSI_CTL_PGM_PGM)
		*cycle |= VME_PROG;
	if (ctl & CA91CX42_VSI_CTL_PGM_DATA)
		*cycle |= VME_DATA;

	return 0;
}