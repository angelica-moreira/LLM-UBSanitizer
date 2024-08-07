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
struct worker_pool {int /*<<< orphan*/  worklist; } ;

/* Variables and functions */
 scalar_t__ __need_more_worker (struct worker_pool*) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool need_more_worker(struct worker_pool *pool)
{
	return !list_empty(&pool->worklist) && __need_more_worker(pool);
}