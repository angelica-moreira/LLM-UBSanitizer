#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  mutex; int /*<<< orphan*/  dep_map; } ;
typedef  TYPE_1__ liblockdep_pthread_mutex_t ;

/* Variables and functions */
 scalar_t__ _RET_IP_ ; 
 int /*<<< orphan*/  lock_acquire (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ pthread_mutex_trylock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int liblockdep_pthread_mutex_trylock(liblockdep_pthread_mutex_t *lock)
{
	lock_acquire(&lock->dep_map, 0, 1, 0, 1, NULL, (unsigned long)_RET_IP_);
	return pthread_mutex_trylock(&lock->mutex) == 0 ? 1 : 0;
}