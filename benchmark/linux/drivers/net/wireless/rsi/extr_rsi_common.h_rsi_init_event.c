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
struct rsi_event {int /*<<< orphan*/  event_queue; int /*<<< orphan*/  event_condition; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int rsi_init_event(struct rsi_event *pevent)
{
	atomic_set(&pevent->event_condition, 1);
	init_waitqueue_head(&pevent->event_queue);
	return 0;
}