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
typedef  scalar_t__ u64 ;

/* Variables and functions */
 scalar_t__ EV67_CYCLES ; 
 scalar_t__ EV67_LAST_ET ; 

__attribute__((used)) static int ev67_raw_event_valid(u64 config)
{
	return config >= EV67_CYCLES && config < EV67_LAST_ET;
}