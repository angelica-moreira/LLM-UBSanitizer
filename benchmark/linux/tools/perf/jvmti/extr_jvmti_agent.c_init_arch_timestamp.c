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
 char* getenv (char*) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int use_arch_timestamp ; 

__attribute__((used)) static void
init_arch_timestamp(void)
{
	char *str = getenv("JITDUMP_USE_ARCH_TIMESTAMP");

	if (!str || !*str || !strcmp(str, "0"))
		return;

	use_arch_timestamp = 1;
}