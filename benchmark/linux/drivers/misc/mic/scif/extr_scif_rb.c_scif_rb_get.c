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
typedef  scalar_t__ u32 ;
struct scif_rb {int current_read_offset; void* rb_base; } ;

/* Variables and functions */
 scalar_t__ scif_rb_count (struct scif_rb*,scalar_t__) ; 

__attribute__((used)) static void *scif_rb_get(struct scif_rb *rb, u32 size)
{
	void *header = NULL;

	if (scif_rb_count(rb, size) >= size)
		header = rb->rb_base + rb->current_read_offset;
	return header;
}