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
typedef  int u64 ;

/* Variables and functions */
#define  GIC_BASER_CACHE_SameAsInner 129 
#define  GIC_BASER_CACHE_nC 128 

u64 vgic_sanitise_outer_cacheability(u64 field)
{
	switch (field) {
	case GIC_BASER_CACHE_SameAsInner:
	case GIC_BASER_CACHE_nC:
		return field;
	default:
		return GIC_BASER_CACHE_nC;
	}
}