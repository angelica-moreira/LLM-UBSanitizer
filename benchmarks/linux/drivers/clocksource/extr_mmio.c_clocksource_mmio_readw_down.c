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
typedef  int u64 ;
struct clocksource {int mask; } ;
struct TYPE_2__ {int /*<<< orphan*/  reg; } ;

/* Variables and functions */
 scalar_t__ readw_relaxed (int /*<<< orphan*/ ) ; 
 TYPE_1__* to_mmio_clksrc (struct clocksource*) ; 

u64 clocksource_mmio_readw_down(struct clocksource *c)
{
	return ~(u64)readw_relaxed(to_mmio_clksrc(c)->reg) & c->mask;
}