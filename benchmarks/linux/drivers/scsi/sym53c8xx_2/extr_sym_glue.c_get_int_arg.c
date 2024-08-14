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
typedef  int /*<<< orphan*/  u_long ;

/* Variables and functions */
 int /*<<< orphan*/  simple_strtoul (char*,char**,int) ; 

__attribute__((used)) static int get_int_arg(char *ptr, int len, u_long *pv)
{
	char *end;

	*pv = simple_strtoul(ptr, &end, 10);
	return (end - ptr);
}