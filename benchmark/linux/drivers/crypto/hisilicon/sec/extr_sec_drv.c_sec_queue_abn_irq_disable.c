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
typedef  int /*<<< orphan*/  u32 ;
struct sec_queue {scalar_t__ regs; } ;

/* Variables and functions */
 scalar_t__ SEC_Q_FAIL_INT_MSK_REG ; 
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void sec_queue_abn_irq_disable(struct sec_queue *queue)
{
	writel_relaxed((u32)~0, queue->regs + SEC_Q_FAIL_INT_MSK_REG);
}