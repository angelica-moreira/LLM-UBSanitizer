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
struct device {int dummy; } ;
typedef  scalar_t__ phys_addr_t ;
typedef  scalar_t__ dma_addr_t ;

/* Variables and functions */
 scalar_t__ ar2315_dev_offset (struct device*) ; 

dma_addr_t __phys_to_dma(struct device *dev, phys_addr_t paddr)
{
	return paddr + ar2315_dev_offset(dev);
}