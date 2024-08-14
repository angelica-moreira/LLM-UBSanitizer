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
struct perf_probe_event {int /*<<< orphan*/  nargs; int /*<<< orphan*/  nsi; int /*<<< orphan*/  target; int /*<<< orphan*/  uprobes; } ;
struct TYPE_2__ {size_t nevents; int target_used; int /*<<< orphan*/  nsi; scalar_t__ target; int /*<<< orphan*/  uprobes; struct perf_probe_event* events; } ;

/* Variables and functions */
 int ENOMEM ; 
 size_t MAX_PROBES ; 
 int /*<<< orphan*/  nsinfo__get (int /*<<< orphan*/ ) ; 
 TYPE_1__ params ; 
 int parse_perf_probe_command (char const*,struct perf_probe_event*) ; 
 int /*<<< orphan*/  pr_debug (char*,size_t,...) ; 
 int /*<<< orphan*/  pr_err (char*,size_t) ; 
 int /*<<< orphan*/  strdup (scalar_t__) ; 

__attribute__((used)) static int parse_probe_event(const char *str)
{
	struct perf_probe_event *pev = &params.events[params.nevents];
	int ret;

	pr_debug("probe-definition(%d): %s\n", params.nevents, str);
	if (++params.nevents == MAX_PROBES) {
		pr_err("Too many probes (> %d) were specified.", MAX_PROBES);
		return -1;
	}

	pev->uprobes = params.uprobes;
	if (params.target) {
		pev->target = strdup(params.target);
		if (!pev->target)
			return -ENOMEM;
		params.target_used = true;
	}

	pev->nsi = nsinfo__get(params.nsi);

	/* Parse a perf-probe command into event */
	ret = parse_perf_probe_command(str, pev);
	pr_debug("%d arguments\n", pev->nargs);

	return ret;
}