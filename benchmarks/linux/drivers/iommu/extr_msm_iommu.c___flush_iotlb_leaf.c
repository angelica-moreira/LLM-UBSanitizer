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
 int /*<<< orphan*/  __flush_iotlb_range (unsigned long,size_t,size_t,int,void*) ; 

__attribute__((used)) static void __flush_iotlb_leaf(unsigned long iova, size_t size,
			       size_t granule, void *cookie)
{
	__flush_iotlb_range(iova, size, granule, true, cookie);
}