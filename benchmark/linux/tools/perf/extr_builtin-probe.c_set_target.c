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
struct TYPE_2__ {int target_used; int uprobes; scalar_t__ target; } ;

/* Variables and functions */
 int ENOMEM ; 
 TYPE_1__ params ; 
 scalar_t__ strcmp (char const*,char*) ; 
 scalar_t__ strdup (char const*) ; 
 int strlen (char const*) ; 

__attribute__((used)) static int set_target(const char *ptr)
{
	int found = 0;
	const char *buf;

	/*
	 * The first argument after options can be an absolute path
	 * to an executable / library or kernel module.
	 *
	 * TODO: Support relative path, and $PATH, $LD_LIBRARY_PATH,
	 * short module name.
	 */
	if (!params.target && ptr && *ptr == '/') {
		params.target = strdup(ptr);
		if (!params.target)
			return -ENOMEM;
		params.target_used = false;

		found = 1;
		buf = ptr + (strlen(ptr) - 3);

		if (strcmp(buf, ".ko"))
			params.uprobes = true;

	}

	return found;
}