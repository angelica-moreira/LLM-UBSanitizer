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
struct mem_cgroup {int dummy; } ;
struct cgroup_subsys_state {int dummy; } ;
struct cftype {int dummy; } ;

/* Variables and functions */
 struct mem_cgroup* mem_cgroup_from_css (struct cgroup_subsys_state*) ; 
 int /*<<< orphan*/  mem_cgroup_swappiness (struct mem_cgroup*) ; 

__attribute__((used)) static u64 mem_cgroup_swappiness_read(struct cgroup_subsys_state *css,
				      struct cftype *cft)
{
	struct mem_cgroup *memcg = mem_cgroup_from_css(css);

	return mem_cgroup_swappiness(memcg);
}