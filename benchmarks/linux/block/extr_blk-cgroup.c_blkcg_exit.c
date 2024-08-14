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
struct task_struct {int /*<<< orphan*/ * throttle_queue; } ;

/* Variables and functions */
 int /*<<< orphan*/  blk_put_queue (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void blkcg_exit(struct task_struct *tsk)
{
	if (tsk->throttle_queue)
		blk_put_queue(tsk->throttle_queue);
	tsk->throttle_queue = NULL;
}