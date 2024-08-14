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
struct push_buffer {scalar_t__ fence; scalar_t__ size; } ;

/* Variables and functions */

__attribute__((used)) static void host1x_pushbuffer_pop(struct push_buffer *pb, unsigned int slots)
{
	/* Advance the next write position */
	pb->fence += slots * 8;

	if (pb->fence >= pb->size)
		pb->fence -= pb->size;
}