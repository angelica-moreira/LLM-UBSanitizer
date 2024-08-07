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
struct pci_dev {int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* dma_alloc_coherent (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ *,size_t,void*,int /*<<< orphan*/ ) ; 
 void* kcalloc (size_t,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *alloc_ring(struct pci_dev *pdev, size_t nelem, size_t elem_size,
			size_t sw_size, dma_addr_t * phys, void *metadata)
{
	size_t len = nelem * elem_size;
	void *s = NULL;
	void *p = dma_alloc_coherent(&pdev->dev, len, phys, GFP_KERNEL);

	if (!p)
		return NULL;
	if (sw_size && metadata) {
		s = kcalloc(nelem, sw_size, GFP_KERNEL);

		if (!s) {
			dma_free_coherent(&pdev->dev, len, p, *phys);
			return NULL;
		}
		*(void **)metadata = s;
	}
	return p;
}