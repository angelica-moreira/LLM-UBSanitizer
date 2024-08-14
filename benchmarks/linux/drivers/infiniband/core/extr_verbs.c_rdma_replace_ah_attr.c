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
struct TYPE_2__ {scalar_t__ sgid_attr; } ;
struct rdma_ah_attr {TYPE_1__ grh; } ;

/* Variables and functions */
 int /*<<< orphan*/  rdma_destroy_ah_attr (struct rdma_ah_attr*) ; 
 int /*<<< orphan*/  rdma_hold_gid_attr (scalar_t__) ; 

void rdma_replace_ah_attr(struct rdma_ah_attr *old,
			  const struct rdma_ah_attr *new)
{
	rdma_destroy_ah_attr(old);
	*old = *new;
	if (old->grh.sgid_attr)
		rdma_hold_gid_attr(old->grh.sgid_attr);
}