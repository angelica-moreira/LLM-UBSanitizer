#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  void u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_5__ {int /*<<< orphan*/  msb; int /*<<< orphan*/  lsb; } ;
struct TYPE_7__ {void* kv_qpt_ptr; int page_count; int page_size; TYPE_1__ hw_qpt_ptr; } ;
struct bna_txq {TYPE_3__ qpt; TYPE_2__* tcb; } ;
struct TYPE_8__ {int /*<<< orphan*/  msb; int /*<<< orphan*/  lsb; } ;
struct bna_mem_descr {void* kva; TYPE_4__ dma; } ;
struct bna_dma_addr {int /*<<< orphan*/  msb; int /*<<< orphan*/  lsb; } ;
struct TYPE_6__ {void** sw_qpt; void* sw_q; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNA_GET_DMA_ADDR (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BNA_SET_DMA_ADDR (int /*<<< orphan*/ ,struct bna_dma_addr*) ; 
 scalar_t__ PAGE_SIZE ; 

__attribute__((used)) static void
bna_txq_qpt_setup(struct bna_txq *txq, int page_count, int page_size,
		struct bna_mem_descr *qpt_mem,
		struct bna_mem_descr *swqpt_mem,
		struct bna_mem_descr *page_mem)
{
	u8 *kva;
	u64 dma;
	struct bna_dma_addr bna_dma;
	int i;

	txq->qpt.hw_qpt_ptr.lsb = qpt_mem->dma.lsb;
	txq->qpt.hw_qpt_ptr.msb = qpt_mem->dma.msb;
	txq->qpt.kv_qpt_ptr = qpt_mem->kva;
	txq->qpt.page_count = page_count;
	txq->qpt.page_size = page_size;

	txq->tcb->sw_qpt = (void **) swqpt_mem->kva;
	txq->tcb->sw_q = page_mem->kva;

	kva = page_mem->kva;
	BNA_GET_DMA_ADDR(&page_mem->dma, dma);

	for (i = 0; i < page_count; i++) {
		txq->tcb->sw_qpt[i] = kva;
		kva += PAGE_SIZE;

		BNA_SET_DMA_ADDR(dma, &bna_dma);
		((struct bna_dma_addr *)txq->qpt.kv_qpt_ptr)[i].lsb =
			bna_dma.lsb;
		((struct bna_dma_addr *)txq->qpt.kv_qpt_ptr)[i].msb =
			bna_dma.msb;
		dma += PAGE_SIZE;
	}
}