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
struct perf_event {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PERF_EF_UPDATE ; 
 int /*<<< orphan*/  pmu_event_stop (struct perf_event*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pmu_event_del(struct perf_event *event, int flags)
{
	pmu_event_stop(event, PERF_EF_UPDATE);
}