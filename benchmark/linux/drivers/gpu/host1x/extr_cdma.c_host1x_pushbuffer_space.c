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
typedef  unsigned int u32 ;
struct push_buffer {unsigned int fence; unsigned int pos; scalar_t__ size; } ;

/* Variables and functions */

__attribute__((used)) static u32 host1x_pushbuffer_space(struct push_buffer *pb)
{
	unsigned int fence = pb->fence;

	if (pb->fence < pb->pos)
		fence += pb->size;

	return (fence - pb->pos) / 8;
}