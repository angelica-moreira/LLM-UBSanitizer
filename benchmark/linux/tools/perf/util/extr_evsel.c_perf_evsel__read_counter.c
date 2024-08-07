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
typedef  int u64 ;
struct TYPE_3__ {int read_format; } ;
struct TYPE_4__ {TYPE_1__ attr; } ;
struct evsel {TYPE_2__ core; } ;

/* Variables and functions */
 int PERF_FORMAT_GROUP ; 
 int perf_evsel__read_group (struct evsel*,int,int) ; 
 int perf_evsel__read_one (struct evsel*,int,int) ; 

int perf_evsel__read_counter(struct evsel *evsel, int cpu, int thread)
{
	u64 read_format = evsel->core.attr.read_format;

	if (read_format & PERF_FORMAT_GROUP)
		return perf_evsel__read_group(evsel, cpu, thread);
	else
		return perf_evsel__read_one(evsel, cpu, thread);
}