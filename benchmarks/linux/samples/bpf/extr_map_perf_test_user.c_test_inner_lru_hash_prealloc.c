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

/* Variables and functions */
 int /*<<< orphan*/  INNER_LRU_HASH_PREALLOC ; 
 int /*<<< orphan*/  do_test_lru (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void test_inner_lru_hash_prealloc(int cpu)
{
	do_test_lru(INNER_LRU_HASH_PREALLOC, cpu);
}