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
struct op_system_config {int dummy; } ;
struct op_register_config {unsigned long mux_select; unsigned long reset_values; unsigned long need_reset; scalar_t__ proc_mode; } ;
struct op_counter_config {int event; unsigned long count; scalar_t__ enabled; } ;

/* Variables and functions */

__attribute__((used)) static void
ev67_reg_setup(struct op_register_config *reg,
	       struct op_counter_config *ctr,
	       struct op_system_config *sys)
{
	unsigned long ctl, reset, need_reset, i;

	/* Select desired events.  */
	ctl = 1UL << 4;		/* Enable ProfileMe mode. */

	/* The event numbers are chosen so we can use them directly if
	   PCTR1 is enabled.  */
	if (ctr[1].enabled) {
		ctl |= (ctr[1].event & 3) << 2;
	} else {
		if (ctr[0].event == 0) /* cycles */
			ctl |= 1UL << 2;
	}
	reg->mux_select = ctl;

	/* Select logging options.  */
	/* ??? Need to come up with some mechanism to trace only
	   selected processes.  EV67 does not have a mechanism to
	   select kernel or user mode only.  For now, enable always.  */
	reg->proc_mode = 0;

	/* EV67 cannot change the width of the counters as with the
	   other implementations.  But fortunately, we can write to
	   the counters and set the value such that it will overflow
	   at the right time.  */
	reset = need_reset = 0;
	for (i = 0; i < 2; ++i) {
		unsigned long count = ctr[i].count;
		if (!ctr[i].enabled)
			continue;

		if (count > 0x100000)
			count = 0x100000;
		ctr[i].count = count;
		reset |= (0x100000 - count) << (i ? 6 : 28);
		if (count != 0x100000)
			need_reset |= 1 << i;
	}
	reg->reset_values = reset;
	reg->need_reset = need_reset;
}