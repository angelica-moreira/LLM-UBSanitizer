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
struct mddev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  md_event_count ; 
 int /*<<< orphan*/  md_event_waiters ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

void md_new_event(struct mddev *mddev)
{
	atomic_inc(&md_event_count);
	wake_up(&md_event_waiters);
}