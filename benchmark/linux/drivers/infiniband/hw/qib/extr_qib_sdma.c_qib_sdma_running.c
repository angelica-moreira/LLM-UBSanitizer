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
struct qib_pportdata {int /*<<< orphan*/  sdma_lock; } ;

/* Variables and functions */
 int __qib_sdma_running (struct qib_pportdata*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int qib_sdma_running(struct qib_pportdata *ppd)
{
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&ppd->sdma_lock, flags);
	ret = __qib_sdma_running(ppd);
	spin_unlock_irqrestore(&ppd->sdma_lock, flags);

	return ret;
}