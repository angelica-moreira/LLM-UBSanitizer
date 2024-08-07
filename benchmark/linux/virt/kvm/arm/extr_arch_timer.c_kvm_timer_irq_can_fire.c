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
struct arch_timer_context {int cnt_ctl; scalar_t__ loaded; } ;

/* Variables and functions */
 int ARCH_TIMER_CTRL_ENABLE ; 
 int ARCH_TIMER_CTRL_IT_MASK ; 
 int /*<<< orphan*/  WARN_ON (int) ; 

__attribute__((used)) static bool kvm_timer_irq_can_fire(struct arch_timer_context *timer_ctx)
{
	WARN_ON(timer_ctx && timer_ctx->loaded);
	return timer_ctx &&
	       !(timer_ctx->cnt_ctl & ARCH_TIMER_CTRL_IT_MASK) &&
		(timer_ctx->cnt_ctl & ARCH_TIMER_CTRL_ENABLE);
}