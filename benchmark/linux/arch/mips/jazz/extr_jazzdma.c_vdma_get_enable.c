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

/* Variables and functions */
 scalar_t__ JAZZ_R4030_CHNL_ENABLE ; 
 int /*<<< orphan*/  printk (char*,int,int) ; 
 int r4030_read_reg32 (scalar_t__) ; 
 scalar_t__ vdma_debug ; 

int vdma_get_enable(int channel)
{
	int enable;

	enable = r4030_read_reg32(JAZZ_R4030_CHNL_ENABLE + (channel << 5));

	if (vdma_debug)
		printk("vdma_get_enable: channel %d: enable=%d\n", channel,
		       enable);

	return enable;
}