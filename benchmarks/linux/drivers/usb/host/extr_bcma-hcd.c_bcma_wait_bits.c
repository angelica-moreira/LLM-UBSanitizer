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
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct bcma_device {int dummy; } ;

/* Variables and functions */
 int ETIMEDOUT ; 
 int bcma_read32 (struct bcma_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int bcma_wait_bits(struct bcma_device *dev, u16 reg, u32 bitmask,
			  int timeout)
{
	int i;
	u32 val;

	for (i = 0; i < timeout; i++) {
		val = bcma_read32(dev, reg);
		if ((val & bitmask) == bitmask)
			return 0;
		udelay(10);
	}

	return -ETIMEDOUT;
}