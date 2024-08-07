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
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_4__ {TYPE_1__* ops; scalar_t__ writes_counter; } ;
struct b43_wldev {TYPE_2__ phy; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* phy_read ) (struct b43_wldev*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  B43_MMIO_PHY_CONTROL ; 
 int /*<<< orphan*/  B43_MMIO_PHY_DATA ; 
 int /*<<< orphan*/  assert_mac_suspended (struct b43_wldev*) ; 
 int /*<<< orphan*/  b43_read16 (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_write16f (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct b43_wldev*,int /*<<< orphan*/ ) ; 

u16 b43_phy_read(struct b43_wldev *dev, u16 reg)
{
	assert_mac_suspended(dev);
	dev->phy.writes_counter = 0;

	if (dev->phy.ops->phy_read)
		return dev->phy.ops->phy_read(dev, reg);

	b43_write16f(dev, B43_MMIO_PHY_CONTROL, reg);
	return b43_read16(dev, B43_MMIO_PHY_DATA);
}