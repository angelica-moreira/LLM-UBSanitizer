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
struct rio_priv {int /*<<< orphan*/  dev; } ;
struct rio_mport {struct rio_priv* priv; } ;
struct TYPE_4__ {int size; int* phys_buffer; int phys; void** virt_buffer; void* virt; scalar_t__ tx_slot; void* dev_id; } ;
struct fsl_rmu {TYPE_2__ msg_tx_ring; TYPE_1__* msg_regs; } ;
struct TYPE_3__ {int /*<<< orphan*/  omr; int /*<<< orphan*/  osr; int /*<<< orphan*/  osar; int /*<<< orphan*/  odqepar; int /*<<< orphan*/  odqdpar; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 struct fsl_rmu* GET_RMM_HANDLE (struct rio_mport*) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_RIO_TX (struct rio_mport*) ; 
 int RIO_MAX_TX_RING_SIZE ; 
 int RIO_MIN_TX_RING_SIZE ; 
 int RIO_MSG_BUFFER_SIZE ; 
 int RIO_MSG_DESC_SIZE ; 
 void* dma_alloc_coherent (int /*<<< orphan*/ ,int,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ ,int,void*,int) ; 
 int /*<<< orphan*/  fsl_rio_tx_handler ; 
 int get_bitmask_order (int) ; 
 int in_be32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  is_power_of_2 (int) ; 
 int /*<<< orphan*/  out_be32 (int /*<<< orphan*/ *,int) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,void*) ; 

int
fsl_open_outb_mbox(struct rio_mport *mport, void *dev_id, int mbox, int entries)
{
	int i, j, rc = 0;
	struct rio_priv *priv = mport->priv;
	struct fsl_rmu *rmu = GET_RMM_HANDLE(mport);

	if ((entries < RIO_MIN_TX_RING_SIZE) ||
		(entries > RIO_MAX_TX_RING_SIZE) || (!is_power_of_2(entries))) {
		rc = -EINVAL;
		goto out;
	}

	/* Initialize shadow copy ring */
	rmu->msg_tx_ring.dev_id = dev_id;
	rmu->msg_tx_ring.size = entries;

	for (i = 0; i < rmu->msg_tx_ring.size; i++) {
		rmu->msg_tx_ring.virt_buffer[i] =
			dma_alloc_coherent(priv->dev, RIO_MSG_BUFFER_SIZE,
				&rmu->msg_tx_ring.phys_buffer[i], GFP_KERNEL);
		if (!rmu->msg_tx_ring.virt_buffer[i]) {
			rc = -ENOMEM;
			for (j = 0; j < rmu->msg_tx_ring.size; j++)
				if (rmu->msg_tx_ring.virt_buffer[j])
					dma_free_coherent(priv->dev,
							RIO_MSG_BUFFER_SIZE,
							rmu->msg_tx_ring.
							virt_buffer[j],
							rmu->msg_tx_ring.
							phys_buffer[j]);
			goto out;
		}
	}

	/* Initialize outbound message descriptor ring */
	rmu->msg_tx_ring.virt = dma_alloc_coherent(priv->dev,
						   rmu->msg_tx_ring.size * RIO_MSG_DESC_SIZE,
						   &rmu->msg_tx_ring.phys,
						   GFP_KERNEL);
	if (!rmu->msg_tx_ring.virt) {
		rc = -ENOMEM;
		goto out_dma;
	}
	rmu->msg_tx_ring.tx_slot = 0;

	/* Point dequeue/enqueue pointers at first entry in ring */
	out_be32(&rmu->msg_regs->odqdpar, rmu->msg_tx_ring.phys);
	out_be32(&rmu->msg_regs->odqepar, rmu->msg_tx_ring.phys);

	/* Configure for snooping */
	out_be32(&rmu->msg_regs->osar, 0x00000004);

	/* Clear interrupt status */
	out_be32(&rmu->msg_regs->osr, 0x000000b3);

	/* Hook up outbound message handler */
	rc = request_irq(IRQ_RIO_TX(mport), fsl_rio_tx_handler, 0,
			 "msg_tx", (void *)mport);
	if (rc < 0)
		goto out_irq;

	/*
	 * Configure outbound message unit
	 *      Snooping
	 *      Interrupts (all enabled, except QEIE)
	 *      Chaining mode
	 *      Disable
	 */
	out_be32(&rmu->msg_regs->omr, 0x00100220);

	/* Set number of entries */
	out_be32(&rmu->msg_regs->omr,
		 in_be32(&rmu->msg_regs->omr) |
		 ((get_bitmask_order(entries) - 2) << 12));

	/* Now enable the unit */
	out_be32(&rmu->msg_regs->omr, in_be32(&rmu->msg_regs->omr) | 0x1);

out:
	return rc;

out_irq:
	dma_free_coherent(priv->dev,
		rmu->msg_tx_ring.size * RIO_MSG_DESC_SIZE,
		rmu->msg_tx_ring.virt, rmu->msg_tx_ring.phys);

out_dma:
	for (i = 0; i < rmu->msg_tx_ring.size; i++)
		dma_free_coherent(priv->dev, RIO_MSG_BUFFER_SIZE,
		rmu->msg_tx_ring.virt_buffer[i],
		rmu->msg_tx_ring.phys_buffer[i]);

	return rc;
}