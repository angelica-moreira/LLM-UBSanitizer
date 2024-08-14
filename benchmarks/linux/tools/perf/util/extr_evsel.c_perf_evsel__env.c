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
struct perf_env {int dummy; } ;
struct evsel {TYPE_1__* evlist; } ;
struct TYPE_2__ {struct perf_env* env; } ;

/* Variables and functions */
 struct perf_env perf_env ; 

struct perf_env *perf_evsel__env(struct evsel *evsel)
{
	if (evsel && evsel->evlist)
		return evsel->evlist->env;
	return &perf_env;
}