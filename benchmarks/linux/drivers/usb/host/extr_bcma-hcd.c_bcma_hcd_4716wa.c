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
typedef  int u32 ;
struct bcma_device {TYPE_2__* bus; } ;
struct TYPE_3__ {int id; } ;
struct TYPE_4__ {int /*<<< orphan*/  drv_mips; TYPE_1__ chipinfo; } ;

/* Variables and functions */
 int bcma_cpu_clock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bcma_read32 (struct bcma_device*,int) ; 
 int /*<<< orphan*/  bcma_write32 (struct bcma_device*,int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void bcma_hcd_4716wa(struct bcma_device *dev)
{
#ifdef CONFIG_BCMA_DRIVER_MIPS
	/* Work around for 4716 failures. */
	if (dev->bus->chipinfo.id == 0x4716) {
		u32 tmp;

		tmp = bcma_cpu_clock(&dev->bus->drv_mips);
		if (tmp >= 480000000)
			tmp = 0x1846b; /* set CDR to 0x11(fast) */
		else if (tmp == 453000000)
			tmp = 0x1046b; /* set CDR to 0x10(slow) */
		else
			tmp = 0;

		/* Change Shim mdio control reg to fix host not acking at
		 * high frequencies
		 */
		if (tmp) {
			bcma_write32(dev, 0x524, 0x1); /* write sel to enable */
			udelay(500);

			bcma_write32(dev, 0x524, tmp);
			udelay(500);
			bcma_write32(dev, 0x524, 0x4ab);
			udelay(500);
			bcma_read32(dev, 0x528);
			bcma_write32(dev, 0x528, 0x80000000);
		}
	}
#endif /* CONFIG_BCMA_DRIVER_MIPS */
}