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
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  for_each_online_package_in_set (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  for_each_online_target_cpu_in_set (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  isst_ctdp_display_information_end (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isst_ctdp_display_information_start (int /*<<< orphan*/ ) ; 
 scalar_t__ max_target_cpus ; 
 int /*<<< orphan*/  outf ; 
 int /*<<< orphan*/  set_pbf_for_cpu ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void set_pbf_disable(void)
{
	int status = 0;

	if (cmd_help) {
		fprintf(stderr,
			"Disable Intel Speed Select Technology base frequency feature [No command arguments are required]\n");
		exit(0);
	}

	isst_ctdp_display_information_start(outf);
	if (max_target_cpus)
		for_each_online_target_cpu_in_set(set_pbf_for_cpu, NULL, NULL,
						  NULL, &status);
	else
		for_each_online_package_in_set(set_pbf_for_cpu, NULL, NULL,
					       NULL, &status);
	isst_ctdp_display_information_end(outf);
}