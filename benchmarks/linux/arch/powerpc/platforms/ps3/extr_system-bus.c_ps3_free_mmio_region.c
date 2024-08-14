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
struct ps3_mmio_region {TYPE_1__* mmio_ops; } ;
struct TYPE_2__ {int (* free ) (struct ps3_mmio_region*) ;} ;

/* Variables and functions */
 int stub1 (struct ps3_mmio_region*) ; 

int ps3_free_mmio_region(struct ps3_mmio_region *r)
{
	return r->mmio_ops->free(r);
}