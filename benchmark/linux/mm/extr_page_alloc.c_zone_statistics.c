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
struct zone {int dummy; } ;
typedef  enum numa_stat_item { ____Placeholder_numa_stat_item } numa_stat_item ;

/* Variables and functions */
 int NUMA_FOREIGN ; 
 int NUMA_HIT ; 
 int NUMA_LOCAL ; 
 int NUMA_MISS ; 
 int NUMA_OTHER ; 
 int /*<<< orphan*/  __inc_numa_state (struct zone*,int) ; 
 scalar_t__ numa_node_id () ; 
 int /*<<< orphan*/  static_branch_likely (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vm_numa_stat_key ; 
 scalar_t__ zone_to_nid (struct zone*) ; 

__attribute__((used)) static inline void zone_statistics(struct zone *preferred_zone, struct zone *z)
{
#ifdef CONFIG_NUMA
	enum numa_stat_item local_stat = NUMA_LOCAL;

	/* skip numa counters update if numa stats is disabled */
	if (!static_branch_likely(&vm_numa_stat_key))
		return;

	if (zone_to_nid(z) != numa_node_id())
		local_stat = NUMA_OTHER;

	if (zone_to_nid(z) == zone_to_nid(preferred_zone))
		__inc_numa_state(z, NUMA_HIT);
	else {
		__inc_numa_state(z, NUMA_MISS);
		__inc_numa_state(preferred_zone, NUMA_FOREIGN);
	}
	__inc_numa_state(z, local_stat);
#endif
}