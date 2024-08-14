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
struct TYPE_2__ {scalar_t__ allow_ints; } ;

/* Variables and functions */
 TYPE_1__ apm_info ; 
 scalar_t__ irqs_disabled_flags (unsigned long) ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int /*<<< orphan*/  local_save_flags (unsigned long) ; 

__attribute__((used)) static inline unsigned long __apm_irq_save(void)
{
	unsigned long flags;
	local_save_flags(flags);
	if (apm_info.allow_ints) {
		if (irqs_disabled_flags(flags))
			local_irq_enable();
	} else
		local_irq_disable();

	return flags;
}