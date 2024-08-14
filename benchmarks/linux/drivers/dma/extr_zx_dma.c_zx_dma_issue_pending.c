#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;
struct zx_dma_dev {TYPE_1__ slave; int /*<<< orphan*/  lock; int /*<<< orphan*/  chan_pending; } ;
struct TYPE_5__ {int /*<<< orphan*/  lock; } ;
struct zx_dma_chan {TYPE_2__ vc; int /*<<< orphan*/  node; int /*<<< orphan*/  phy; } ;
struct dma_chan {int /*<<< orphan*/  device; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,TYPE_2__*) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct zx_dma_chan* to_zx_chan (struct dma_chan*) ; 
 struct zx_dma_dev* to_zx_dma (int /*<<< orphan*/ ) ; 
 scalar_t__ vchan_issue_pending (TYPE_2__*) ; 
 int /*<<< orphan*/  zx_dma_task (struct zx_dma_dev*) ; 

__attribute__((used)) static void zx_dma_issue_pending(struct dma_chan *chan)
{
	struct zx_dma_chan *c = to_zx_chan(chan);
	struct zx_dma_dev *d = to_zx_dma(chan->device);
	unsigned long flags;
	int issue = 0;

	spin_lock_irqsave(&c->vc.lock, flags);
	/* add request to vc->desc_issued */
	if (vchan_issue_pending(&c->vc)) {
		spin_lock(&d->lock);
		if (!c->phy && list_empty(&c->node)) {
			/* if new channel, add chan_pending */
			list_add_tail(&c->node, &d->chan_pending);
			issue = 1;
			dev_dbg(d->slave.dev, "vchan %p: issued\n", &c->vc);
		}
		spin_unlock(&d->lock);
	} else {
		dev_dbg(d->slave.dev, "vchan %p: nothing to issue\n", &c->vc);
	}
	spin_unlock_irqrestore(&c->vc.lock, flags);

	if (issue)
		zx_dma_task(d);
}