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
struct rtc_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ is_rtc_hctosys (struct rtc_device*) ; 
 int /*<<< orphan*/  remove_proc_entry (char*,int /*<<< orphan*/ *) ; 

void rtc_proc_del_device(struct rtc_device *rtc)
{
	if (is_rtc_hctosys(rtc))
		remove_proc_entry("driver/rtc", NULL);
}