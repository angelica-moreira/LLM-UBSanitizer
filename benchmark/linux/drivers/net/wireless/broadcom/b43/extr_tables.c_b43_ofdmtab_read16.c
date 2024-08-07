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
typedef  int u16 ;
struct TYPE_2__ {struct b43_phy_g* g; } ;
struct b43_wldev {TYPE_1__ phy; } ;
struct b43_phy_g {scalar_t__ ofdmtab_addr_direction; int ofdmtab_addr; } ;

/* Variables and functions */
 scalar_t__ B43_OFDMTAB_DIRECTION_READ ; 
 int /*<<< orphan*/  B43_PHY_OTABLECTL ; 
 int /*<<< orphan*/  B43_PHY_OTABLEI ; 
 int /*<<< orphan*/  assert_sizes () ; 
 int b43_phy_read (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_phy_write (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 

u16 b43_ofdmtab_read16(struct b43_wldev *dev, u16 table, u16 offset)
{
	struct b43_phy_g *gphy = dev->phy.g;
	u16 addr;

	addr = table + offset;
	if ((gphy->ofdmtab_addr_direction != B43_OFDMTAB_DIRECTION_READ) ||
	    (addr - 1 != gphy->ofdmtab_addr)) {
		/* The hardware has a different address in memory. Update it. */
		b43_phy_write(dev, B43_PHY_OTABLECTL, addr);
		gphy->ofdmtab_addr_direction = B43_OFDMTAB_DIRECTION_READ;
	}
	gphy->ofdmtab_addr = addr;

	return b43_phy_read(dev, B43_PHY_OTABLEI);

	/* Some compiletime assertions... */
	assert_sizes();
}