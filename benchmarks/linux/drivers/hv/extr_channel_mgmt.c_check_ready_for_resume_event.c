#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  ready_for_resume_event; int /*<<< orphan*/  nr_chan_fixup_on_resume; } ;

/* Variables and functions */
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 TYPE_1__ vmbus_connection ; 

__attribute__((used)) static void check_ready_for_resume_event(void)
{
	/*
	 * If all the old primary channels have been fixed up, then it's safe
	 * to resume.
	 */
	if (atomic_dec_and_test(&vmbus_connection.nr_chan_fixup_on_resume))
		complete(&vmbus_connection.ready_for_resume_event);
}