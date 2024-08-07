#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct lpfc_hba {int /*<<< orphan*/  lpfc_hrb_pool; int /*<<< orphan*/  lpfc_drb_pool; } ;
struct TYPE_4__ {int /*<<< orphan*/  phys; void* virt; } ;
struct TYPE_3__ {void* virt; int /*<<< orphan*/  phys; } ;
struct hbq_dmabuf {int /*<<< orphan*/  total_size; TYPE_2__ hbuf; TYPE_1__ dbuf; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  LPFC_DATA_BUF_SIZE ; 
 void* dma_pool_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dma_pool_free (int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct hbq_dmabuf*) ; 
 struct hbq_dmabuf* kzalloc (int,int /*<<< orphan*/ ) ; 

struct hbq_dmabuf *
lpfc_sli4_rb_alloc(struct lpfc_hba *phba)
{
	struct hbq_dmabuf *dma_buf;

	dma_buf = kzalloc(sizeof(struct hbq_dmabuf), GFP_KERNEL);
	if (!dma_buf)
		return NULL;

	dma_buf->hbuf.virt = dma_pool_alloc(phba->lpfc_hrb_pool, GFP_KERNEL,
					    &dma_buf->hbuf.phys);
	if (!dma_buf->hbuf.virt) {
		kfree(dma_buf);
		return NULL;
	}
	dma_buf->dbuf.virt = dma_pool_alloc(phba->lpfc_drb_pool, GFP_KERNEL,
					    &dma_buf->dbuf.phys);
	if (!dma_buf->dbuf.virt) {
		dma_pool_free(phba->lpfc_hrb_pool, dma_buf->hbuf.virt,
			      dma_buf->hbuf.phys);
		kfree(dma_buf);
		return NULL;
	}
	dma_buf->total_size = LPFC_DATA_BUF_SIZE;
	return dma_buf;
}