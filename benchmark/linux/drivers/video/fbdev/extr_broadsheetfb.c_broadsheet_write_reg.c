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
typedef  int /*<<< orphan*/  u16 ;
struct broadsheetfb_par {TYPE_1__* board; } ;
struct TYPE_2__ {scalar_t__ mmio_write; } ;

/* Variables and functions */
 int /*<<< orphan*/  broadsheet_gpio_write_reg (struct broadsheetfb_par*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  broadsheet_mmio_write_reg (struct broadsheetfb_par*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void broadsheet_write_reg(struct broadsheetfb_par *par, u16 reg,
					u16 data)
{
	if (par->board->mmio_write)
		broadsheet_mmio_write_reg(par, reg, data);
	else
		broadsheet_gpio_write_reg(par, reg, data);
}