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
struct TYPE_2__ {int chan_id; } ;
struct sirfsoc_dma_chan {int /*<<< orphan*/  lock; int /*<<< orphan*/  free; int /*<<< orphan*/  queued; int /*<<< orphan*/  active; TYPE_1__ chan; } ;
struct sirfsoc_dma {int type; scalar_t__ base; } ;
struct dma_chan {int dummy; } ;

/* Variables and functions */
 scalar_t__ SIRFSOC_DMA_CH_INT ; 
 scalar_t__ SIRFSOC_DMA_CH_LOOP_CTRL ; 
 scalar_t__ SIRFSOC_DMA_CH_LOOP_CTRL_CLR_ATLAS7 ; 
 scalar_t__ SIRFSOC_DMA_CH_VALID ; 
 int SIRFSOC_DMA_INT_ALL_ATLAS7 ; 
 scalar_t__ SIRFSOC_DMA_INT_ATLAS7 ; 
 scalar_t__ SIRFSOC_DMA_INT_EN ; 
 scalar_t__ SIRFSOC_DMA_INT_EN_ATLAS7 ; 
 scalar_t__ SIRFSOC_DMA_INT_EN_CLR ; 
 scalar_t__ SIRFSOC_DMA_LOOP_CTRL_ATLAS7 ; 
 scalar_t__ SIRFSOC_DMA_VALID_ATLAS7 ; 
#define  SIRFSOC_DMA_VER_A6 130 
#define  SIRFSOC_DMA_VER_A7V1 129 
#define  SIRFSOC_DMA_VER_A7V2 128 
 struct sirfsoc_dma* dma_chan_to_sirfsoc_dma (TYPE_1__*) ; 
 struct sirfsoc_dma_chan* dma_chan_to_sirfsoc_dma_chan (struct dma_chan*) ; 
 int /*<<< orphan*/  list_splice_tail_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static int sirfsoc_dma_terminate_all(struct dma_chan *chan)
{
	struct sirfsoc_dma_chan *schan = dma_chan_to_sirfsoc_dma_chan(chan);
	struct sirfsoc_dma *sdma = dma_chan_to_sirfsoc_dma(&schan->chan);
	int cid = schan->chan.chan_id;
	unsigned long flags;

	spin_lock_irqsave(&schan->lock, flags);

	switch (sdma->type) {
	case SIRFSOC_DMA_VER_A7V1:
		writel_relaxed(1 << cid, sdma->base + SIRFSOC_DMA_INT_EN_CLR);
		writel_relaxed(1 << cid, sdma->base + SIRFSOC_DMA_CH_INT);
		writel_relaxed((1 << cid) | 1 << (cid + 16),
			       sdma->base +
			       SIRFSOC_DMA_CH_LOOP_CTRL_CLR_ATLAS7);
		writel_relaxed(1 << cid, sdma->base + SIRFSOC_DMA_CH_VALID);
		break;
	case SIRFSOC_DMA_VER_A7V2:
		writel_relaxed(0, sdma->base + SIRFSOC_DMA_INT_EN_ATLAS7);
		writel_relaxed(SIRFSOC_DMA_INT_ALL_ATLAS7,
			       sdma->base + SIRFSOC_DMA_INT_ATLAS7);
		writel_relaxed(0, sdma->base + SIRFSOC_DMA_LOOP_CTRL_ATLAS7);
		writel_relaxed(0, sdma->base + SIRFSOC_DMA_VALID_ATLAS7);
		break;
	case SIRFSOC_DMA_VER_A6:
		writel_relaxed(readl_relaxed(sdma->base + SIRFSOC_DMA_INT_EN) &
			       ~(1 << cid), sdma->base + SIRFSOC_DMA_INT_EN);
		writel_relaxed(readl_relaxed(sdma->base +
					     SIRFSOC_DMA_CH_LOOP_CTRL) &
			       ~((1 << cid) | 1 << (cid + 16)),
			       sdma->base + SIRFSOC_DMA_CH_LOOP_CTRL);
		writel_relaxed(1 << cid, sdma->base + SIRFSOC_DMA_CH_VALID);
		break;
	default:
		break;
	}

	list_splice_tail_init(&schan->active, &schan->free);
	list_splice_tail_init(&schan->queued, &schan->free);

	spin_unlock_irqrestore(&schan->lock, flags);

	return 0;
}