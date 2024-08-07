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
struct TYPE_2__ {int /*<<< orphan*/  irq; } ;
struct dw_apb_clock_event_device {TYPE_1__ timer; } ;

/* Variables and functions */
 int /*<<< orphan*/  apbt_disable_int (TYPE_1__*) ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 

void dw_apb_clockevent_pause(struct dw_apb_clock_event_device *dw_ced)
{
	disable_irq(dw_ced->timer.irq);
	apbt_disable_int(&dw_ced->timer);
}