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
typedef  int /*<<< orphan*/  uint32_t ;
struct sg_mapping_iter {int dummy; } ;

/* Variables and functions */
 scalar_t__ likely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sg_dwiter_get_next_block (struct sg_mapping_iter*,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  sg_dwiter_read_buffer (struct sg_mapping_iter*) ; 

uint32_t cb710_sg_dwiter_read_next_block(struct sg_mapping_iter *miter)
{
	uint32_t *ptr = NULL;

	if (likely(sg_dwiter_get_next_block(miter, &ptr)))
		return ptr ? *ptr : 0;

	return sg_dwiter_read_buffer(miter);
}