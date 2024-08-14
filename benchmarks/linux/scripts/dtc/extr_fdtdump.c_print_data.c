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
 int /*<<< orphan*/  GET_CELL (char const*) ; 
 int fdt32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ util_is_printable_string (char const*,int) ; 

__attribute__((used)) static void print_data(const char *data, int len)
{
	int i;
	const char *p = data;

	/* no data, don't print */
	if (len == 0)
		return;

	if (util_is_printable_string(data, len)) {
		printf(" = \"%s\"", (const char *)data);
	} else if ((len % 4) == 0) {
		printf(" = <");
		for (i = 0; i < len; i += 4)
			printf("0x%08x%s", fdt32_to_cpu(GET_CELL(p)),
			       i < (len - 4) ? " " : "");
		printf(">");
	} else {
		printf(" = [");
		for (i = 0; i < len; i++)
			printf("%02x%s", *p++, i < len - 1 ? " " : "");
		printf("]");
	}
}