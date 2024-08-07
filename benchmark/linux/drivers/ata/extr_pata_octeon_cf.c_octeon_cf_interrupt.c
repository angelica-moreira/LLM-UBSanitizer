#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int done; } ;
union cvmx_mio_boot_dma_intx {void* u64; TYPE_5__ s; } ;
struct TYPE_8__ {int /*<<< orphan*/  en; } ;
union cvmx_mio_boot_dma_cfgx {TYPE_3__ s; void* u64; } ;
typedef  int u8 ;
struct octeon_cf_port {int dma_finished; int /*<<< orphan*/  delayed_finish; scalar_t__ dma_base; } ;
struct TYPE_7__ {int flags; } ;
struct ata_queued_cmd {int /*<<< orphan*/  cursg; TYPE_2__ tf; } ;
struct TYPE_9__ {int /*<<< orphan*/  altstatus_addr; } ;
struct TYPE_6__ {int /*<<< orphan*/  active_tag; } ;
struct ata_port {TYPE_4__ ioaddr; TYPE_1__ link; struct octeon_cf_port* private_data; } ;
struct ata_host {int n_ports; int /*<<< orphan*/  lock; struct ata_port** ports; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ATA_BUSY ; 
 int ATA_DRQ ; 
 int ATA_TFLAG_POLLING ; 
 scalar_t__ DMA_CFG ; 
 scalar_t__ DMA_INT ; 
 int /*<<< orphan*/  DPRINTK (char*) ; 
 int /*<<< orphan*/  HRTIMER_MODE_REL ; 
 int /*<<< orphan*/  IRQ_RETVAL (unsigned int) ; 
 int OCTEON_CF_BUSY_POLL_INTERVAL ; 
 struct ata_queued_cmd* ata_qc_from_tag (struct ata_port*,int /*<<< orphan*/ ) ; 
 void* cvmx_read_csr (scalar_t__) ; 
 int /*<<< orphan*/  cvmx_write_csr (scalar_t__,void*) ; 
 int /*<<< orphan*/  hrtimer_start_range_ns (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int ioread8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ns_to_ktime (int) ; 
 unsigned int octeon_cf_dma_finished (struct ata_port*,struct ata_queued_cmd*) ; 
 int /*<<< orphan*/  octeon_cf_dma_start (struct ata_queued_cmd*) ; 
 int /*<<< orphan*/  sg_is_last (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sg_next (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static irqreturn_t octeon_cf_interrupt(int irq, void *dev_instance)
{
	struct ata_host *host = dev_instance;
	struct octeon_cf_port *cf_port;
	int i;
	unsigned int handled = 0;
	unsigned long flags;

	spin_lock_irqsave(&host->lock, flags);

	DPRINTK("ENTER\n");
	for (i = 0; i < host->n_ports; i++) {
		u8 status;
		struct ata_port *ap;
		struct ata_queued_cmd *qc;
		union cvmx_mio_boot_dma_intx dma_int;
		union cvmx_mio_boot_dma_cfgx dma_cfg;

		ap = host->ports[i];
		cf_port = ap->private_data;

		dma_int.u64 = cvmx_read_csr(cf_port->dma_base + DMA_INT);
		dma_cfg.u64 = cvmx_read_csr(cf_port->dma_base + DMA_CFG);

		qc = ata_qc_from_tag(ap, ap->link.active_tag);

		if (!qc || (qc->tf.flags & ATA_TFLAG_POLLING))
			continue;

		if (dma_int.s.done && !dma_cfg.s.en) {
			if (!sg_is_last(qc->cursg)) {
				qc->cursg = sg_next(qc->cursg);
				handled = 1;
				octeon_cf_dma_start(qc);
				continue;
			} else {
				cf_port->dma_finished = 1;
			}
		}
		if (!cf_port->dma_finished)
			continue;
		status = ioread8(ap->ioaddr.altstatus_addr);
		if (status & (ATA_BUSY | ATA_DRQ)) {
			/*
			 * We are busy, try to handle it later.  This
			 * is the DMA finished interrupt, and it could
			 * take a little while for the card to be
			 * ready for more commands.
			 */
			/* Clear DMA irq. */
			dma_int.u64 = 0;
			dma_int.s.done = 1;
			cvmx_write_csr(cf_port->dma_base + DMA_INT,
				       dma_int.u64);
			hrtimer_start_range_ns(&cf_port->delayed_finish,
					       ns_to_ktime(OCTEON_CF_BUSY_POLL_INTERVAL),
					       OCTEON_CF_BUSY_POLL_INTERVAL / 5,
					       HRTIMER_MODE_REL);
			handled = 1;
		} else {
			handled |= octeon_cf_dma_finished(ap, qc);
		}
	}
	spin_unlock_irqrestore(&host->lock, flags);
	DPRINTK("EXIT\n");
	return IRQ_RETVAL(handled);
}