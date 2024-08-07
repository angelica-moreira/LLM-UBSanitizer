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
struct ceph_osdmap {int /*<<< orphan*/  primary_temp; } ;

/* Variables and functions */
 int /*<<< orphan*/  __decode_primary_temp ; 
 int decode_pg_mapping (void**,void*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int decode_new_primary_temp(void **p, void *end,
				   struct ceph_osdmap *map)
{
	return decode_pg_mapping(p, end, &map->primary_temp,
				 __decode_primary_temp, true);
}