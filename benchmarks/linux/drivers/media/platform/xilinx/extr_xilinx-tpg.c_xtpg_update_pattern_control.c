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
struct TYPE_2__ {int /*<<< orphan*/  lock; } ;
struct xtpg_device {TYPE_1__ ctrl_handler; } ;

/* Variables and functions */
 int /*<<< orphan*/  __xtpg_update_pattern_control (struct xtpg_device*,int,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void xtpg_update_pattern_control(struct xtpg_device *xtpg,
					bool passthrough, bool pattern)
{
	mutex_lock(xtpg->ctrl_handler.lock);
	__xtpg_update_pattern_control(xtpg, passthrough, pattern);
	mutex_unlock(xtpg->ctrl_handler.lock);
}