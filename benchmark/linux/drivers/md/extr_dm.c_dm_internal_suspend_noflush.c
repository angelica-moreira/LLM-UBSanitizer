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
struct mapped_device {int /*<<< orphan*/  suspend_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  DM_SUSPEND_NOFLUSH_FLAG ; 
 int /*<<< orphan*/  __dm_internal_suspend (struct mapped_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

void dm_internal_suspend_noflush(struct mapped_device *md)
{
	mutex_lock(&md->suspend_lock);
	__dm_internal_suspend(md, DM_SUSPEND_NOFLUSH_FLAG);
	mutex_unlock(&md->suspend_lock);
}