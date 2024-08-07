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
struct cpuinfo_x86 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  find_num_cache_leaves (struct cpuinfo_x86*) ; 
 int /*<<< orphan*/  num_cache_leaves ; 

void init_hygon_cacheinfo(struct cpuinfo_x86 *c)
{
	num_cache_leaves = find_num_cache_leaves(c);
}