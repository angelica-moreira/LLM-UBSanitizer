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
struct lcd_panel {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpio_set_value (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void innovator1610_panel_disable(struct lcd_panel *panel)
{
	/* set GPIO13, GPIO14 and GPIO15 low */
	gpio_set_value(14, 0);
	gpio_set_value(15, 0);
}