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
 int strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 

__attribute__((used)) static int is_json_file(const char *name)
{
	const char *suffix;

	if (strlen(name) < 5)
		return 0;

	suffix = name + strlen(name) - 5;

	if (strncmp(suffix, ".json", 5) == 0)
		return 1;
	return 0;
}