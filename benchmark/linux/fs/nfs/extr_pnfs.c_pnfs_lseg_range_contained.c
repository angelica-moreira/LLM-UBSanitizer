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
typedef  scalar_t__ u64 ;
struct pnfs_layout_range {scalar_t__ offset; int /*<<< orphan*/  length; } ;

/* Variables and functions */
 scalar_t__ pnfs_end_offset (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
pnfs_lseg_range_contained(const struct pnfs_layout_range *l1,
		 const struct pnfs_layout_range *l2)
{
	u64 start1 = l1->offset;
	u64 end1 = pnfs_end_offset(start1, l1->length);
	u64 start2 = l2->offset;
	u64 end2 = pnfs_end_offset(start2, l2->length);

	return (start1 <= start2) && (end1 >= end2);
}