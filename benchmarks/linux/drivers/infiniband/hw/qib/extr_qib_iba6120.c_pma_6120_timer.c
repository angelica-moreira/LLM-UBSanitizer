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
typedef  void* u64 ;
struct timer_list {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  pma_sample_interval; } ;
struct qib_ibport {TYPE_1__ rvp; } ;
struct qib_pportdata {struct qib_ibport ibport_data; } ;
struct qib_chip_specific {scalar_t__ pma_sample_status; void* sword; void* rword; void* spkts; void* rpkts; void* xmit_wait; int /*<<< orphan*/  pma_timer; struct qib_pportdata* ppd; } ;

/* Variables and functions */
 scalar_t__ IB_PMA_SAMPLE_STATUS_DONE ; 
 scalar_t__ IB_PMA_SAMPLE_STATUS_RUNNING ; 
 scalar_t__ IB_PMA_SAMPLE_STATUS_STARTED ; 
 struct qib_chip_specific* cs ; 
 struct qib_chip_specific* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  pma_timer ; 
 int /*<<< orphan*/  qib_snapshot_counters (struct qib_pportdata*,void**,void**,void**,void**,void**) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ usecs_to_jiffies (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pma_6120_timer(struct timer_list *t)
{
	struct qib_chip_specific *cs = from_timer(cs, t, pma_timer);
	struct qib_pportdata *ppd = cs->ppd;
	struct qib_ibport *ibp = &ppd->ibport_data;
	unsigned long flags;

	spin_lock_irqsave(&ibp->rvp.lock, flags);
	if (cs->pma_sample_status == IB_PMA_SAMPLE_STATUS_STARTED) {
		cs->pma_sample_status = IB_PMA_SAMPLE_STATUS_RUNNING;
		qib_snapshot_counters(ppd, &cs->sword, &cs->rword,
				      &cs->spkts, &cs->rpkts, &cs->xmit_wait);
		mod_timer(&cs->pma_timer,
		      jiffies + usecs_to_jiffies(ibp->rvp.pma_sample_interval));
	} else if (cs->pma_sample_status == IB_PMA_SAMPLE_STATUS_RUNNING) {
		u64 ta, tb, tc, td, te;

		cs->pma_sample_status = IB_PMA_SAMPLE_STATUS_DONE;
		qib_snapshot_counters(ppd, &ta, &tb, &tc, &td, &te);

		cs->sword = ta - cs->sword;
		cs->rword = tb - cs->rword;
		cs->spkts = tc - cs->spkts;
		cs->rpkts = td - cs->rpkts;
		cs->xmit_wait = te - cs->xmit_wait;
	}
	spin_unlock_irqrestore(&ibp->rvp.lock, flags);
}