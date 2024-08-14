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
struct dm_region_hash {int region_shift; } ;
typedef  int sector_t ;
typedef  int region_t ;

/* Variables and functions */

__attribute__((used)) static region_t dm_rh_sector_to_region(struct dm_region_hash *rh, sector_t sector)
{
	return sector >> rh->region_shift;
}