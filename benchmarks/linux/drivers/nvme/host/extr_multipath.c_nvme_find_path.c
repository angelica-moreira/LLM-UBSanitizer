#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct nvme_ns_head {TYPE_1__* subsys; int /*<<< orphan*/  srcu; int /*<<< orphan*/ * current_path; } ;
struct nvme_ns {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  iopolicy; } ;

/* Variables and functions */
 scalar_t__ NVME_IOPOLICY_RR ; 
 scalar_t__ READ_ONCE (int /*<<< orphan*/ ) ; 
 struct nvme_ns* __nvme_find_path (struct nvme_ns_head*,int) ; 
 int numa_node_id () ; 
 int /*<<< orphan*/  nvme_path_is_optimized (struct nvme_ns*) ; 
 struct nvme_ns* nvme_round_robin_path (struct nvme_ns_head*,int,struct nvme_ns*) ; 
 struct nvme_ns* srcu_dereference (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 

inline struct nvme_ns *nvme_find_path(struct nvme_ns_head *head)
{
	int node = numa_node_id();
	struct nvme_ns *ns;

	ns = srcu_dereference(head->current_path[node], &head->srcu);
	if (READ_ONCE(head->subsys->iopolicy) == NVME_IOPOLICY_RR && ns)
		ns = nvme_round_robin_path(head, node, ns);
	if (unlikely(!ns || !nvme_path_is_optimized(ns)))
		ns = __nvme_find_path(head, node);
	return ns;
}