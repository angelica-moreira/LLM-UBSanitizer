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
struct b43_wldev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43_MMIO_RADIO24_CONTROL ; 
 int /*<<< orphan*/  B43_MMIO_RADIO24_DATA ; 
 int /*<<< orphan*/  b43_write16 (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_write16f (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void b43_phy_ac_op_radio_write(struct b43_wldev *dev, u16 reg,
				      u16 value)
{
	b43_write16f(dev, B43_MMIO_RADIO24_CONTROL, reg);
	b43_write16(dev, B43_MMIO_RADIO24_DATA, value);
}