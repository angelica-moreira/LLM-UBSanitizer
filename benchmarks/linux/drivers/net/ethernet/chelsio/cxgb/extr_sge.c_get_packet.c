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
struct sk_buff {int /*<<< orphan*/  data; } ;
struct pci_dev {int dummy; } ;
struct freelQ_ce {struct sk_buff* skb; } ;
struct freelQ {size_t cidx; int credits; struct freelQ_ce* centries; } ;
struct adapter {int /*<<< orphan*/  napi; struct pci_dev* pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  PCI_DMA_FROMDEVICE ; 
 unsigned int copybreak ; 
 int /*<<< orphan*/  dma_addr ; 
 int /*<<< orphan*/  dma_len ; 
 int /*<<< orphan*/  dma_unmap_addr (struct freelQ_ce const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_unmap_len (struct freelQ_ce const*,int /*<<< orphan*/ ) ; 
 struct sk_buff* napi_alloc_skb (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  pci_dma_sync_single_for_cpu (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_dma_sync_single_for_device (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_unmap_single (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  prefetch (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  recycle_fl_buf (struct freelQ*,size_t) ; 
 int /*<<< orphan*/  skb_copy_from_linear_data (struct sk_buff*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  skb_put (struct sk_buff*,unsigned int) ; 

__attribute__((used)) static inline struct sk_buff *get_packet(struct adapter *adapter,
					 struct freelQ *fl, unsigned int len)
{
	const struct freelQ_ce *ce = &fl->centries[fl->cidx];
	struct pci_dev *pdev = adapter->pdev;
	struct sk_buff *skb;

	if (len < copybreak) {
		skb = napi_alloc_skb(&adapter->napi, len);
		if (!skb)
			goto use_orig_buf;

		skb_put(skb, len);
		pci_dma_sync_single_for_cpu(pdev,
					    dma_unmap_addr(ce, dma_addr),
					    dma_unmap_len(ce, dma_len),
					    PCI_DMA_FROMDEVICE);
		skb_copy_from_linear_data(ce->skb, skb->data, len);
		pci_dma_sync_single_for_device(pdev,
					       dma_unmap_addr(ce, dma_addr),
					       dma_unmap_len(ce, dma_len),
					       PCI_DMA_FROMDEVICE);
		recycle_fl_buf(fl, fl->cidx);
		return skb;
	}

use_orig_buf:
	if (fl->credits < 2) {
		recycle_fl_buf(fl, fl->cidx);
		return NULL;
	}

	pci_unmap_single(pdev, dma_unmap_addr(ce, dma_addr),
			 dma_unmap_len(ce, dma_len), PCI_DMA_FROMDEVICE);
	skb = ce->skb;
	prefetch(skb->data);

	skb_put(skb, len);
	return skb;
}