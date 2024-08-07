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
typedef  int u8 ;

/* Variables and functions */
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 

__attribute__((used)) static char *__ipr_format_res_path(u8 *res_path, char *buffer, int len)
{
	int i;
	char *p = buffer;

	*p = '\0';
	p += snprintf(p, buffer + len - p, "%02X", res_path[0]);
	for (i = 1; res_path[i] != 0xff && ((i * 3) < len); i++)
		p += snprintf(p, buffer + len - p, "-%02X", res_path[i]);

	return buffer;
}