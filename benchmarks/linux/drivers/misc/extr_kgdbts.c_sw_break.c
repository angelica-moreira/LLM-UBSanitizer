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
 int /*<<< orphan*/  break_helper (char*,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ force_hwbrks ; 

__attribute__((used)) static void sw_break(char *arg)
{
	break_helper(force_hwbrks ? "Z1" : "Z0", arg, 0);
}