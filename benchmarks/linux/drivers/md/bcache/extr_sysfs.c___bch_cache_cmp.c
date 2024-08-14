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
typedef  int uint16_t ;

/* Variables and functions */
 int /*<<< orphan*/  cond_resched () ; 

__attribute__((used)) static int __bch_cache_cmp(const void *l, const void *r)
{
	cond_resched();
	return *((uint16_t *)r) - *((uint16_t *)l);
}