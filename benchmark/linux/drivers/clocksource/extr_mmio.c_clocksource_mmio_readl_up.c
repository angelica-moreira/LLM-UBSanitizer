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
typedef  int /*<<< orphan*/  u64 ;
struct clocksource {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  reg; } ;

/* Variables and functions */
 int /*<<< orphan*/  readl_relaxed (int /*<<< orphan*/ ) ; 
 TYPE_1__* to_mmio_clksrc (struct clocksource*) ; 

u64 clocksource_mmio_readl_up(struct clocksource *c)
{
	return (u64)readl_relaxed(to_mmio_clksrc(c)->reg);
}