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
 scalar_t__ json_output ; 
 int /*<<< orphan*/  json_wtr ; 
 int /*<<< orphan*/  jsonw_int_field (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int read_procfs (char*) ; 

__attribute__((used)) static void probe_jit_enable(void)
{
	int res;

	/* No support for C-style ouptut */

	res = read_procfs("/proc/sys/net/core/bpf_jit_enable");
	if (json_output) {
		jsonw_int_field(json_wtr, "bpf_jit_enable", res);
	} else {
		switch (res) {
		case 0:
			printf("JIT compiler is disabled\n");
			break;
		case 1:
			printf("JIT compiler is enabled\n");
			break;
		case 2:
			printf("JIT compiler is enabled with debugging traces in kernel logs\n");
			break;
		case -1:
			printf("Unable to retrieve JIT-compiler status\n");
			break;
		default:
			printf("JIT-compiler status has unknown value %d\n",
			       res);
		}
	}
}