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
struct evsel {int dummy; } ;
struct event_key {int /*<<< orphan*/  exit_reasons; int /*<<< orphan*/  key; } ;

/* Variables and functions */
 int /*<<< orphan*/  icpt_insn_decoder (unsigned long) ; 
 unsigned long perf_evsel__intval (struct evsel*,struct perf_sample*,char*) ; 
 int /*<<< orphan*/  sie_icpt_insn_codes ; 

__attribute__((used)) static void event_icpt_insn_get_key(struct evsel *evsel,
				    struct perf_sample *sample,
				    struct event_key *key)
{
	unsigned long insn;

	insn = perf_evsel__intval(evsel, sample, "instruction");
	key->key = icpt_insn_decoder(insn);
	key->exit_reasons = sie_icpt_insn_codes;
}