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
struct rpmsg_endpoint {TYPE_1__* ops; } ;
struct TYPE_2__ {int (* trysend ) (struct rpmsg_endpoint*,void*,int) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int ENXIO ; 
 scalar_t__ WARN_ON (int) ; 
 int stub1 (struct rpmsg_endpoint*,void*,int) ; 

int rpmsg_trysend(struct rpmsg_endpoint *ept, void *data, int len)
{
	if (WARN_ON(!ept))
		return -EINVAL;
	if (!ept->ops->trysend)
		return -ENXIO;

	return ept->ops->trysend(ept, data, len);
}