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
struct bcom_task {int /*<<< orphan*/  tasknum; } ;

/* Variables and functions */
 int /*<<< orphan*/  bcom_disable_task (int /*<<< orphan*/ ) ; 

void
bcom_disable(struct bcom_task *tsk)
{
	bcom_disable_task(tsk->tasknum);
}