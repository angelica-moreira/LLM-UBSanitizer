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
struct perf_sample {int dummy; } ;
struct evsel {int /*<<< orphan*/  name; } ;
struct event_key {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  hcall_event_get_key (struct evsel*,struct perf_sample*,struct event_key*) ; 
 int /*<<< orphan*/ * kvm_events_tp ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool hcall_event_begin(struct evsel *evsel,
			      struct perf_sample *sample, struct event_key *key)
{
	if (!strcmp(evsel->name, kvm_events_tp[2])) {
		hcall_event_get_key(evsel, sample, key);
		return true;
	}

	return false;
}