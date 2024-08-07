#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* regs; } ;
struct TYPE_3__ {int /*<<< orphan*/  prio; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_iic ; 
 int /*<<< orphan*/  out_be64 (int /*<<< orphan*/ *,int) ; 
 TYPE_2__* this_cpu_ptr (int /*<<< orphan*/ *) ; 

void iic_setup_cpu(void)
{
	out_be64(&this_cpu_ptr(&cpu_iic)->regs->prio, 0xff);
}