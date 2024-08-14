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
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  crw_handler_wait_q ; 
 int /*<<< orphan*/  crw_nr_req ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

void crw_handle_channel_report(void)
{
	atomic_inc(&crw_nr_req);
	wake_up(&crw_handler_wait_q);
}