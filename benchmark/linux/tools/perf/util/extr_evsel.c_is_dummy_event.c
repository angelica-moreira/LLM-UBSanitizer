#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ type; scalar_t__ config; } ;
struct TYPE_4__ {TYPE_1__ attr; } ;
struct evsel {TYPE_2__ core; } ;

/* Variables and functions */
 scalar_t__ PERF_COUNT_SW_DUMMY ; 
 scalar_t__ PERF_TYPE_SOFTWARE ; 

__attribute__((used)) static bool is_dummy_event(struct evsel *evsel)
{
	return (evsel->core.attr.type == PERF_TYPE_SOFTWARE) &&
	       (evsel->core.attr.config == PERF_COUNT_SW_DUMMY);
}