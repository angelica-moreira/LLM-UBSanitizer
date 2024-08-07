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
typedef  int u8 ;
typedef  int u16 ;
struct b43_wldev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43_MMIO_GPIO_CONTROL ; 
 int b43_read16 (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_write16 (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void b43_led_turn_off(struct b43_wldev *dev, u8 led_index,
			     bool activelow)
{
	u16 ctl;

	ctl = b43_read16(dev, B43_MMIO_GPIO_CONTROL);
	if (activelow)
		ctl |= (1 << led_index);
	else
		ctl &= ~(1 << led_index);
	b43_write16(dev, B43_MMIO_GPIO_CONTROL, ctl);
}