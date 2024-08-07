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
struct pit_data {int dummy; } ;
struct clock_event_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  at91sam926x_pit_reset (struct pit_data*) ; 
 struct pit_data* clkevt_to_pit_data (struct clock_event_device*) ; 

__attribute__((used)) static void at91sam926x_pit_resume(struct clock_event_device *cedev)
{
	struct pit_data *data = clkevt_to_pit_data(cedev);

	at91sam926x_pit_reset(data);
}