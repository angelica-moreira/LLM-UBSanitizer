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
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct TYPE_2__ {int wdata_shift; } ;

/* Variables and functions */
 TYPE_1__* at93c ; 
 int /*<<< orphan*/  at93c_cycle_clk (int) ; 
 int at93c_reg_read () ; 
 int /*<<< orphan*/  at93c_reg_write (int) ; 
 int /*<<< orphan*/  lasat_ndelay (int) ; 

__attribute__((used)) static void at93c_write_databit(u8 bit)
{
	u32 data = at93c_reg_read();
	if (bit)
		data |= 1 << at93c->wdata_shift;
	else
		data &= ~(1 << at93c->wdata_shift);

	at93c_reg_write(data);
	lasat_ndelay(100);
	at93c_cycle_clk(data);
}