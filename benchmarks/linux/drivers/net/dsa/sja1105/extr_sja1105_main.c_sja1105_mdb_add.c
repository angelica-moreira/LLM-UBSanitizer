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
struct switchdev_obj_port_mdb {int /*<<< orphan*/  vid; int /*<<< orphan*/  addr; } ;
struct dsa_switch {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sja1105_fdb_add (struct dsa_switch*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sja1105_mdb_add(struct dsa_switch *ds, int port,
			    const struct switchdev_obj_port_mdb *mdb)
{
	sja1105_fdb_add(ds, port, mdb->addr, mdb->vid);
}