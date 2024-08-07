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
typedef  int /*<<< orphan*/  u16 ;
struct mv88e6xxx_chip {TYPE_1__* ds; } ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int mv88e6xxx_g2_pvt_write (struct mv88e6xxx_chip*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mv88e6xxx_has_pvt (struct mv88e6xxx_chip*) ; 
 int /*<<< orphan*/  mv88e6xxx_port_vlan (struct mv88e6xxx_chip*,int,int) ; 

__attribute__((used)) static int mv88e6xxx_pvt_map(struct mv88e6xxx_chip *chip, int dev, int port)
{
	u16 pvlan = 0;

	if (!mv88e6xxx_has_pvt(chip))
		return -EOPNOTSUPP;

	/* Skip the local source device, which uses in-chip port VLAN */
	if (dev != chip->ds->index)
		pvlan = mv88e6xxx_port_vlan(chip, dev, port);

	return mv88e6xxx_g2_pvt_write(chip, dev, port, pvlan);
}