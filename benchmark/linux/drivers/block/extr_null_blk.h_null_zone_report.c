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
struct gendisk {int dummy; } ;
struct blk_zone {int dummy; } ;
typedef  int /*<<< orphan*/  sector_t ;

/* Variables and functions */
 int EOPNOTSUPP ; 

__attribute__((used)) static inline int null_zone_report(struct gendisk *disk, sector_t sector,
				   struct blk_zone *zones,
				   unsigned int *nr_zones)
{
	return -EOPNOTSUPP;
}