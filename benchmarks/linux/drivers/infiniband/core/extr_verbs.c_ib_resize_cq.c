#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct ib_cq {TYPE_2__* device; } ;
struct TYPE_3__ {int (* resize_cq ) (struct ib_cq*,int,int /*<<< orphan*/ *) ;} ;
struct TYPE_4__ {TYPE_1__ ops; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int stub1 (struct ib_cq*,int,int /*<<< orphan*/ *) ; 

int ib_resize_cq(struct ib_cq *cq, int cqe)
{
	return cq->device->ops.resize_cq ?
		cq->device->ops.resize_cq(cq, cqe, NULL) : -EOPNOTSUPP;
}