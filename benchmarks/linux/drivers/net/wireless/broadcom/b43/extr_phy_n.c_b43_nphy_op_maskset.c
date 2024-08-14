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
struct TYPE_2__ {int writes_counter; } ;
struct b43_wldev {TYPE_1__ phy; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43_MMIO_PHY_CONTROL ; 
 int /*<<< orphan*/  B43_MMIO_PHY_DATA ; 
 int /*<<< orphan*/  b43_maskset16 (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_write16f (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  check_phyreg (struct b43_wldev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void b43_nphy_op_maskset(struct b43_wldev *dev, u16 reg, u16 mask,
				 u16 set)
{
	check_phyreg(dev, reg);
	b43_write16f(dev, B43_MMIO_PHY_CONTROL, reg);
	b43_maskset16(dev, B43_MMIO_PHY_DATA, mask, set);
	dev->phy.writes_counter = 1;
}