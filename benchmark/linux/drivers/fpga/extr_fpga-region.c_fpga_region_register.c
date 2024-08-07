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
struct fpga_region {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int device_add (int /*<<< orphan*/ *) ; 

int fpga_region_register(struct fpga_region *region)
{
	return device_add(&region->dev);
}