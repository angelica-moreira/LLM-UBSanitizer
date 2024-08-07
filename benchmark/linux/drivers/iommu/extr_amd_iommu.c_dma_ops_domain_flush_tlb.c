#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  lock; } ;
struct dma_ops_domain {TYPE_1__ domain; } ;

/* Variables and functions */
 int /*<<< orphan*/  domain_flush_complete (TYPE_1__*) ; 
 int /*<<< orphan*/  domain_flush_tlb (TYPE_1__*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void dma_ops_domain_flush_tlb(struct dma_ops_domain *dom)
{
	unsigned long flags;

	spin_lock_irqsave(&dom->domain.lock, flags);
	domain_flush_tlb(&dom->domain);
	domain_flush_complete(&dom->domain);
	spin_unlock_irqrestore(&dom->domain.lock, flags);
}