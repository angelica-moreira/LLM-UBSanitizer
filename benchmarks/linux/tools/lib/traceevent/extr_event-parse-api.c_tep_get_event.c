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
struct tep_handle {int nr_events; struct tep_event** events; } ;
struct tep_event {int dummy; } ;

/* Variables and functions */

struct tep_event *tep_get_event(struct tep_handle *tep, int index)
{
	if (tep && tep->events && index < tep->nr_events)
		return tep->events[index];

	return NULL;
}