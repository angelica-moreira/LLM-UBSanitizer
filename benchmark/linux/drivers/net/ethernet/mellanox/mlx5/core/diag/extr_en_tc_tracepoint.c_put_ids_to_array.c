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
struct flow_action_entry {int id; } ;

/* Variables and functions */

void put_ids_to_array(int *ids,
		      const struct flow_action_entry *entries,
		      unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		ids[i] = entries[i].id;
}