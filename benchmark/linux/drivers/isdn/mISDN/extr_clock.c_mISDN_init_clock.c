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
typedef  int /*<<< orphan*/  u_int ;

/* Variables and functions */
 int /*<<< orphan*/ * debug ; 
 int /*<<< orphan*/  iclock_timestamp ; 
 int /*<<< orphan*/  ktime_get () ; 

void
mISDN_init_clock(u_int *dp)
{
	debug = dp;
	iclock_timestamp = ktime_get();
}