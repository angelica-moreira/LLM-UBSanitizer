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
typedef  int /*<<< orphan*/  u64 ;
struct z3fold_pool {int /*<<< orphan*/  pages_nr; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic64_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static u64 z3fold_get_pool_size(struct z3fold_pool *pool)
{
	return atomic64_read(&pool->pages_nr);
}