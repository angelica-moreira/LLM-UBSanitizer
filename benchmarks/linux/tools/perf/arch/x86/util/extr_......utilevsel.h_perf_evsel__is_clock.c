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
struct evsel {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SOFTWARE ; 
 int /*<<< orphan*/  SW_CPU_CLOCK ; 
 int /*<<< orphan*/  SW_TASK_CLOCK ; 
 scalar_t__ perf_evsel__match (struct evsel*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool perf_evsel__is_clock(struct evsel *evsel)
{
	return perf_evsel__match(evsel, SOFTWARE, SW_CPU_CLOCK) ||
	       perf_evsel__match(evsel, SOFTWARE, SW_TASK_CLOCK);
}