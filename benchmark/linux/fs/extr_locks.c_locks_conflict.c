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
struct file_lock {scalar_t__ fl_type; } ;

/* Variables and functions */
 scalar_t__ F_WRLCK ; 

__attribute__((used)) static bool locks_conflict(struct file_lock *caller_fl,
			   struct file_lock *sys_fl)
{
	if (sys_fl->fl_type == F_WRLCK)
		return true;
	if (caller_fl->fl_type == F_WRLCK)
		return true;
	return false;
}