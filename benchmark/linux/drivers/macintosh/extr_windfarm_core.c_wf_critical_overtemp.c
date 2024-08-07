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
 int /*<<< orphan*/  UMH_WAIT_EXEC ; 
 int call_usermodehelper (char const*,char**,char**,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int wf_critical_overtemp(void)
{
	static char const critical_overtemp_path[] = "/sbin/critical_overtemp";
	char *argv[] = { (char *)critical_overtemp_path, NULL };
	static char *envp[] = { "HOME=/",
				"TERM=linux",
				"PATH=/sbin:/usr/sbin:/bin:/usr/bin",
				NULL };

	return call_usermodehelper(critical_overtemp_path,
				   argv, envp, UMH_WAIT_EXEC);
}