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
 int EVTCHN_2L_NR_CHANNELS ; 

__attribute__((used)) static unsigned evtchn_2l_max_channels(void)
{
	return EVTCHN_2L_NR_CHANNELS;
}