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
struct TYPE_2__ {int precise_ip; } ;
struct perf_event {TYPE_1__ attr; } ;

/* Variables and functions */
 void intel_pebs_aliases_core2 (struct perf_event*) ; 
 void intel_pebs_aliases_precdist (struct perf_event*) ; 

__attribute__((used)) static void intel_pebs_aliases_skl(struct perf_event *event)
{
	if (event->attr.precise_ip < 3)
		return intel_pebs_aliases_core2(event);
	return intel_pebs_aliases_precdist(event);
}