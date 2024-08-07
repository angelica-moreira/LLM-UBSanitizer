#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct urb {int status; int /*<<< orphan*/  actual_length; TYPE_2__* dev; struct catc* context; } ;
struct catc {int /*<<< orphan*/  tx_lock; TYPE_3__* netdev; int /*<<< orphan*/  flags; scalar_t__ tx_ptr; } ;
struct TYPE_5__ {int /*<<< orphan*/  tx_errors; } ;
struct TYPE_7__ {TYPE_1__ stats; } ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ECONNRESET ; 
 int /*<<< orphan*/  TX_RUNNING ; 
 int catc_tx_run (struct catc*) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  netif_trans_update (TYPE_3__*) ; 
 int /*<<< orphan*/  netif_wake_queue (TYPE_3__*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void catc_tx_done(struct urb *urb)
{
	struct catc *catc = urb->context;
	unsigned long flags;
	int r, status = urb->status;

	if (status == -ECONNRESET) {
		dev_dbg(&urb->dev->dev, "Tx Reset.\n");
		urb->status = 0;
		netif_trans_update(catc->netdev);
		catc->netdev->stats.tx_errors++;
		clear_bit(TX_RUNNING, &catc->flags);
		netif_wake_queue(catc->netdev);
		return;
	}

	if (status) {
		dev_dbg(&urb->dev->dev, "tx_done, status %d, length %d\n",
			status, urb->actual_length);
		return;
	}

	spin_lock_irqsave(&catc->tx_lock, flags);

	if (catc->tx_ptr) {
		r = catc_tx_run(catc);
		if (unlikely(r < 0))
			clear_bit(TX_RUNNING, &catc->flags);
	} else {
		clear_bit(TX_RUNNING, &catc->flags);
	}

	netif_wake_queue(catc->netdev);

	spin_unlock_irqrestore(&catc->tx_lock, flags);
}