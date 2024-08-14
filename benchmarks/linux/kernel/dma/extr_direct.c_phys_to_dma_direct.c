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
typedef  int /*<<< orphan*/  phys_addr_t ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  __phys_to_dma (struct device*,int /*<<< orphan*/ ) ; 
 scalar_t__ force_dma_unencrypted (struct device*) ; 
 int /*<<< orphan*/  phys_to_dma (struct device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline dma_addr_t phys_to_dma_direct(struct device *dev,
		phys_addr_t phys)
{
	if (force_dma_unencrypted(dev))
		return __phys_to_dma(dev, phys);
	return phys_to_dma(dev, phys);
}