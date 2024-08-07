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
typedef  int /*<<< orphan*/  phandle ;
typedef  int /*<<< orphan*/  namebuf ;

/* Variables and functions */
 int /*<<< orphan*/  prom_getproperty (int /*<<< orphan*/ ,char*,char*,int) ; 
 scalar_t__ strcmp (char*,char const*) ; 

int prom_nodematch(phandle node, const char *name)
{
	char namebuf[128];
	prom_getproperty(node, "name", namebuf, sizeof(namebuf));
	if (strcmp(namebuf, name) == 0)
		return 1;
	return 0;
}