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
 int /*<<< orphan*/  OMAP1510_FPGA_LCD_PANEL_CONTROL ; 
 int /*<<< orphan*/  __raw_writeb (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int innovator1510_panel_enable(struct lcd_panel *panel)
{
	__raw_writeb(0x7, OMAP1510_FPGA_LCD_PANEL_CONTROL);
	return 0;
}