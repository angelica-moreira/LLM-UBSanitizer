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
struct TYPE_2__ {int ext_ctrl; } ;

/* Variables and functions */
 TYPE_1__ lcd_dma ; 

void omap_set_lcd_dma_ext_controller(int external)
{
	lcd_dma.ext_ctrl = external;
}