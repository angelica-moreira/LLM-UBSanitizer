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
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {struct clock_event_device cevd; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ U300_TIMER_APP_GPT1IA ; 
 int /*<<< orphan*/  U300_TIMER_APP_GPT1IA_IRQ_ACK ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 
 TYPE_1__ u300_clockevent_data ; 
 scalar_t__ u300_timer_base ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static irqreturn_t u300_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = &u300_clockevent_data.cevd;
	/* ACK/Clear timer IRQ for the APP GPT1 Timer */

	writel(U300_TIMER_APP_GPT1IA_IRQ_ACK,
		u300_timer_base + U300_TIMER_APP_GPT1IA);
	evt->event_handler(evt);
	return IRQ_HANDLED;
}