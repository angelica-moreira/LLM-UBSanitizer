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
struct dm_cache_policy {void (* tick ) (struct dm_cache_policy*,int) ;} ;

/* Variables and functions */
 void stub1 (struct dm_cache_policy*,int) ; 

__attribute__((used)) static inline void policy_tick(struct dm_cache_policy *p, bool can_block)
{
	if (p->tick)
		return p->tick(p, can_block);
}