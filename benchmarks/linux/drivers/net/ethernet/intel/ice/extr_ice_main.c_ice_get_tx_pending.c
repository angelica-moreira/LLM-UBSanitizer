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
typedef  scalar_t__ u16 ;
struct ice_ring {scalar_t__ next_to_clean; scalar_t__ next_to_use; scalar_t__ count; } ;

/* Variables and functions */

__attribute__((used)) static u16 ice_get_tx_pending(struct ice_ring *ring)
{
	u16 head, tail;

	head = ring->next_to_clean;
	tail = ring->next_to_use;

	if (head != tail)
		return (head < tail) ?
			tail - head : (tail + ring->count - head);
	return 0;
}