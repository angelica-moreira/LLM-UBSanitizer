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

/* Variables and functions */
 int /*<<< orphan*/  TICK_DEP_BIT_PERF_EVENTS ; 
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nr_freq_events ; 
 int /*<<< orphan*/  nr_freq_lock ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tick_nohz_dep_clear (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void unaccount_freq_event_nohz(void)
{
#ifdef CONFIG_NO_HZ_FULL
	spin_lock(&nr_freq_lock);
	if (atomic_dec_and_test(&nr_freq_events))
		tick_nohz_dep_clear(TICK_DEP_BIT_PERF_EVENTS);
	spin_unlock(&nr_freq_lock);
#endif
}