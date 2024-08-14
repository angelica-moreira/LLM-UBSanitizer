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
 int /*<<< orphan*/  astrcat (char**,char const*) ; 
 scalar_t__ is_absolute_path (char const*) ; 
 char* make_nonrelative_path (char const*) ; 

__attribute__((used)) static void add_path(char **out, const char *path)
{
	if (path && *path) {
		if (is_absolute_path(path))
			astrcat(out, path);
		else
			astrcat(out, make_nonrelative_path(path));

		astrcat(out, ":");
	}
}