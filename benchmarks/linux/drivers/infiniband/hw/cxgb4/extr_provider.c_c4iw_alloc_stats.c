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
typedef  scalar_t__ u8 ;
struct rdma_hw_stats {int dummy; } ;
struct ib_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 scalar_t__ NR_COUNTERS ; 
 int /*<<< orphan*/  RDMA_HW_STATS_DEFAULT_LIFESPAN ; 
 int /*<<< orphan*/  names ; 
 struct rdma_hw_stats* rdma_alloc_hw_stats_struct (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct rdma_hw_stats *c4iw_alloc_stats(struct ib_device *ibdev,
					      u8 port_num)
{
	BUILD_BUG_ON(ARRAY_SIZE(names) != NR_COUNTERS);

	if (port_num != 0)
		return NULL;

	return rdma_alloc_hw_stats_struct(names, NR_COUNTERS,
					  RDMA_HW_STATS_DEFAULT_LIFESPAN);
}