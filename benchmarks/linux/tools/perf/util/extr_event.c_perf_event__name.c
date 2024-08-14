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
 unsigned int ARRAY_SIZE (char const**) ; 
 char const** perf_event__names ; 

const char *perf_event__name(unsigned int id)
{
	if (id >= ARRAY_SIZE(perf_event__names))
		return "INVALID";
	if (!perf_event__names[id])
		return "UNKNOWN";
	return perf_event__names[id];
}