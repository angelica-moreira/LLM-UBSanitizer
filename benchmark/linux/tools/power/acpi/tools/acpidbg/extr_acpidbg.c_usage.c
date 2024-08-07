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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 

void usage(FILE *file, char *progname)
{
	fprintf(file, "usage: %s [-b cmd] [-f file] [-h]\n", progname);
	fprintf(file, "\nOptions:\n");
	fprintf(file, "  -b     Specify command to be executed in batch mode\n");
	fprintf(file, "  -f     Specify interface file other than");
	fprintf(file, "         /sys/kernel/debug/acpi/acpidbg\n");
	fprintf(file, "  -h     Print this help message\n");
}