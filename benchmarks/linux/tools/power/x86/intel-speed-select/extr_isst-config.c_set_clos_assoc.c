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

/* Variables and functions */
 scalar_t__ cmd_help ; 
 int current_clos ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  for_each_online_target_cpu_in_set (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ max_target_cpus ; 
 int /*<<< orphan*/  set_clos_assoc_for_cpu ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void set_clos_assoc(void)
{
	if (cmd_help) {
		fprintf(stderr, "Associate a clos id to a CPU\n");
		fprintf(stderr,
			"\tSpecify targeted clos id with [--clos|-c]\n");
		exit(0);
	}

	if (current_clos < 0 || current_clos > 3) {
		fprintf(stderr, "Invalid clos id\n");
		exit(0);
	}
	if (max_target_cpus)
		for_each_online_target_cpu_in_set(set_clos_assoc_for_cpu, NULL,
						  NULL, NULL, NULL);
	else {
		fprintf(stderr,
			"Invalid target cpu. Specify with [-c|--cpu]\n");
	}
}