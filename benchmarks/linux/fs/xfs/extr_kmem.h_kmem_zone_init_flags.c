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
typedef  int /*<<< orphan*/  slab_flags_t ;
typedef  int /*<<< orphan*/  kmem_zone_t ;

/* Variables and functions */
 int /*<<< orphan*/ * kmem_cache_create (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (void*)) ; 

__attribute__((used)) static inline kmem_zone_t *
kmem_zone_init_flags(int size, char *zone_name, slab_flags_t flags,
		     void (*construct)(void *))
{
	return kmem_cache_create(zone_name, size, 0, flags, construct);
}