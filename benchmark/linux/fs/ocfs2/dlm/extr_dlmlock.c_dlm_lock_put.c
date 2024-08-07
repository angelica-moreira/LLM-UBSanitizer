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
struct dlm_lock {int /*<<< orphan*/  lock_refs; } ;

/* Variables and functions */
 int /*<<< orphan*/  dlm_lock_release ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void dlm_lock_put(struct dlm_lock *lock)
{
	kref_put(&lock->lock_refs, dlm_lock_release);
}