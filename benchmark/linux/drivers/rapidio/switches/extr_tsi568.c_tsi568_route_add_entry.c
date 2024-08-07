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
typedef  scalar_t__ u16 ;
struct rio_mport {int dummy; } ;

/* Variables and functions */
 scalar_t__ RIO_GLOBAL_TABLE ; 
 int /*<<< orphan*/  SPBC_ROUTE_CFG_DESTID ; 
 int /*<<< orphan*/  SPBC_ROUTE_CFG_PORT ; 
 int /*<<< orphan*/  SPP_ROUTE_CFG_DESTID (scalar_t__) ; 
 int /*<<< orphan*/  SPP_ROUTE_CFG_PORT (scalar_t__) ; 
 int /*<<< orphan*/  rio_mport_write_config_32 (struct rio_mport*,scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int
tsi568_route_add_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
		       u16 table, u16 route_destid, u8 route_port)
{
	if (table == RIO_GLOBAL_TABLE) {
		rio_mport_write_config_32(mport, destid, hopcount,
					SPBC_ROUTE_CFG_DESTID, route_destid);
		rio_mport_write_config_32(mport, destid, hopcount,
					SPBC_ROUTE_CFG_PORT, route_port);
	} else {
		rio_mport_write_config_32(mport, destid, hopcount,
					SPP_ROUTE_CFG_DESTID(table),
					route_destid);
		rio_mport_write_config_32(mport, destid, hopcount,
					SPP_ROUTE_CFG_PORT(table), route_port);
	}

	udelay(10);

	return 0;
}