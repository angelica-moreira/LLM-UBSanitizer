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
typedef  int /*<<< orphan*/  u16 ;
struct mv88e6060_priv {int dummy; } ;
struct dsa_switch {struct mv88e6060_priv* priv; } ;

/* Variables and functions */
 int mv88e6060_port_to_phy_addr (int) ; 
 int reg_write (struct mv88e6060_priv*,int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
mv88e6060_phy_write(struct dsa_switch *ds, int port, int regnum, u16 val)
{
	struct mv88e6060_priv *priv = ds->priv;
	int addr;

	addr = mv88e6060_port_to_phy_addr(port);
	if (addr == -1)
		return 0xffff;

	return reg_write(priv, addr, regnum, val);
}