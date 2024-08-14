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
 int /*<<< orphan*/  NUM_CONTROLS_HT2 ; 
 int /*<<< orphan*/  NUM_COUNTERS_HT2 ; 
 int /*<<< orphan*/  num_controls ; 
 int /*<<< orphan*/  num_counters ; 
 int smp_num_siblings ; 

__attribute__((used)) static inline void setup_num_counters(void)
{
#ifdef CONFIG_SMP
	if (smp_num_siblings == 2) {
		num_counters = NUM_COUNTERS_HT2;
		num_controls = NUM_CONTROLS_HT2;
	}
#endif
}