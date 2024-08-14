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
 void* NTP_PHASE_LIMIT ; 
 int /*<<< orphan*/  STA_UNSYNC ; 
 int /*<<< orphan*/  TIME64_MAX ; 
 int /*<<< orphan*/  ntp_next_leap_sec ; 
 int /*<<< orphan*/  ntp_update_frequency () ; 
 int /*<<< orphan*/  pps_clear () ; 
 int /*<<< orphan*/  tick_length ; 
 int /*<<< orphan*/  tick_length_base ; 
 scalar_t__ time_adjust ; 
 void* time_esterror ; 
 void* time_maxerror ; 
 scalar_t__ time_offset ; 
 int /*<<< orphan*/  time_status ; 

void ntp_clear(void)
{
	time_adjust	= 0;		/* stop active adjtime() */
	time_status	|= STA_UNSYNC;
	time_maxerror	= NTP_PHASE_LIMIT;
	time_esterror	= NTP_PHASE_LIMIT;

	ntp_update_frequency();

	tick_length	= tick_length_base;
	time_offset	= 0;

	ntp_next_leap_sec = TIME64_MAX;
	/* Clear PPS state variables */
	pps_clear();
}