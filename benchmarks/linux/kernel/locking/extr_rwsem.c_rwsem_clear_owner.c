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
struct rw_semaphore {int /*<<< orphan*/  owner; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_long_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void rwsem_clear_owner(struct rw_semaphore *sem)
{
	atomic_long_set(&sem->owner, 0);
}