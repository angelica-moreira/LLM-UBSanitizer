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
typedef  int /*<<< orphan*/  gfp_t ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 void* dma_alloc_attrs (int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  to_vmd_dev (struct device*) ; 

__attribute__((used)) static void *vmd_alloc(struct device *dev, size_t size, dma_addr_t *addr,
		       gfp_t flag, unsigned long attrs)
{
	return dma_alloc_attrs(to_vmd_dev(dev), size, addr, flag, attrs);
}