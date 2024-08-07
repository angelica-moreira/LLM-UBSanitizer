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
typedef  int /*<<< orphan*/  value ;
typedef  int /*<<< orphan*/  header ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  format_and_print (int /*<<< orphan*/ *,int,char*,char*) ; 
 int get_physical_die_id (int) ; 
 int get_physical_package_id (int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,unsigned int) ; 

void isst_ctdp_display_core_info(int cpu, FILE *outf, char *prefix,
				 unsigned int val)
{
	char header[256];
	char value[256];

	snprintf(header, sizeof(header), "package-%d",
		 get_physical_package_id(cpu));
	format_and_print(outf, 1, header, NULL);
	snprintf(header, sizeof(header), "die-%d", get_physical_die_id(cpu));
	format_and_print(outf, 2, header, NULL);
	snprintf(header, sizeof(header), "cpu-%d", cpu);
	format_and_print(outf, 3, header, NULL);

	snprintf(value, sizeof(value), "%u", val);
	format_and_print(outf, 4, prefix, value);

	format_and_print(outf, 1, NULL, NULL);
}