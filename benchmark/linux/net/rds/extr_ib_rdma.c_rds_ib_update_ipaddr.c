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
struct rds_ib_device {int dummy; } ;
struct in6_addr {int /*<<< orphan*/ * s6_addr32; } ;

/* Variables and functions */
 int rds_ib_add_ipaddr (struct rds_ib_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rds_ib_dev_put (struct rds_ib_device*) ; 
 struct rds_ib_device* rds_ib_get_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rds_ib_remove_ipaddr (struct rds_ib_device*,int /*<<< orphan*/ ) ; 

int rds_ib_update_ipaddr(struct rds_ib_device *rds_ibdev,
			 struct in6_addr *ipaddr)
{
	struct rds_ib_device *rds_ibdev_old;

	rds_ibdev_old = rds_ib_get_device(ipaddr->s6_addr32[3]);
	if (!rds_ibdev_old)
		return rds_ib_add_ipaddr(rds_ibdev, ipaddr->s6_addr32[3]);

	if (rds_ibdev_old != rds_ibdev) {
		rds_ib_remove_ipaddr(rds_ibdev_old, ipaddr->s6_addr32[3]);
		rds_ib_dev_put(rds_ibdev_old);
		return rds_ib_add_ipaddr(rds_ibdev, ipaddr->s6_addr32[3]);
	}
	rds_ib_dev_put(rds_ibdev_old);

	return 0;
}