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
struct parsed_partitions {int /*<<< orphan*/  parts; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct parsed_partitions*) ; 
 int /*<<< orphan*/  vfree (int /*<<< orphan*/ ) ; 

void free_partitions(struct parsed_partitions *state)
{
	vfree(state->parts);
	kfree(state);
}