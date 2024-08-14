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
struct perf_thread_map {int dummy; } ;
struct TYPE_3__ {int disabled; } ;
struct TYPE_4__ {TYPE_1__ attr; } ;
struct evsel {TYPE_2__ core; } ;
struct evlist {int dummy; } ;

/* Variables and functions */
 int TEST_FAIL ; 
 int TEST_OK ; 
 int /*<<< orphan*/  UINT_MAX ; 
 struct evsel* evlist__last (struct evlist*) ; 
 scalar_t__ evsel__enable (struct evsel*) ; 
 int /*<<< orphan*/  getpid () ; 
 int perf_evsel__open_per_thread (struct evsel*,struct perf_thread_map*) ; 
 int /*<<< orphan*/  perf_thread_map__put (struct perf_thread_map*) ; 
 int /*<<< orphan*/  pr_debug (char*) ; 
 struct perf_thread_map* thread_map__new (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int attach__current_disabled(struct evlist *evlist)
{
	struct evsel *evsel = evlist__last(evlist);
	struct perf_thread_map *threads;
	int err;

	pr_debug("attaching to current thread as disabled\n");

	threads = thread_map__new(-1, getpid(), UINT_MAX);
	if (threads == NULL) {
		pr_debug("thread_map__new\n");
		return -1;
	}

	evsel->core.attr.disabled = 1;

	err = perf_evsel__open_per_thread(evsel, threads);
	if (err) {
		pr_debug("Failed to open event cpu-clock:u\n");
		return err;
	}

	perf_thread_map__put(threads);
	return evsel__enable(evsel) == 0 ? TEST_OK : TEST_FAIL;
}