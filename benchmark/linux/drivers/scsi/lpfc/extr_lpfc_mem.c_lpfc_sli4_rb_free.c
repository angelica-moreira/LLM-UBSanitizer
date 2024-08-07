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
struct lpfc_hba {int /*<<< orphan*/  lpfc_drb_pool; int /*<<< orphan*/  lpfc_hrb_pool; } ;
struct TYPE_4__ {int /*<<< orphan*/  phys; int /*<<< orphan*/  virt; } ;
struct TYPE_3__ {int /*<<< orphan*/  phys; int /*<<< orphan*/  virt; } ;
struct hbq_dmabuf {TYPE_2__ dbuf; TYPE_1__ hbuf; } ;

/* Variables and functions */
 int /*<<< orphan*/  dma_pool_free (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct hbq_dmabuf*) ; 

void
lpfc_sli4_rb_free(struct lpfc_hba *phba, struct hbq_dmabuf *dmab)
{
	dma_pool_free(phba->lpfc_hrb_pool, dmab->hbuf.virt, dmab->hbuf.phys);
	dma_pool_free(phba->lpfc_drb_pool, dmab->dbuf.virt, dmab->dbuf.phys);
	kfree(dmab);
}