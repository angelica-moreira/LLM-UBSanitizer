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
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 char* strstr (char const*,char*) ; 

__attribute__((used)) static bool is_x86_retpoline(const char *name)
{
	const char *p = strstr(name, "__x86_indirect_thunk_");

	return p == name || !strcmp(name, "__indirect_thunk_start");
}