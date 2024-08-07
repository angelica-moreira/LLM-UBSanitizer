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
struct broadsheetfb_par {int /*<<< orphan*/  waitq; } ;

/* Variables and functions */
 int /*<<< orphan*/  RDY_GPIO_PIN ; 
 int /*<<< orphan*/  gpio_get_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wait_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int am300_wait_event(struct broadsheetfb_par *par)
{
	/* todo: improve err recovery */
	wait_event(par->waitq, gpio_get_value(RDY_GPIO_PIN));
	return 0;
}