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
struct parport {int dummy; } ;
struct TYPE_2__ {int rd_data_reg_sel; int wd_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 TYPE_1__ sound_ym ; 

__attribute__((used)) static void
parport_atari_data_forward(struct parport *p)
{
	unsigned long flags;

	local_irq_save(flags);
	/* Soundchip port B as output. */
	sound_ym.rd_data_reg_sel = 7;
	sound_ym.wd_data = sound_ym.rd_data_reg_sel | 0x40;
	local_irq_restore(flags);
}