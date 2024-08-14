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
struct ice_ring {int dummy; } ;

/* Variables and functions */
 unsigned int ICE_DESC_UNUSED (struct ice_ring*) ; 
 int __ice_maybe_stop_tx (struct ice_ring*,unsigned int) ; 
 scalar_t__ likely (int) ; 

__attribute__((used)) static int ice_maybe_stop_tx(struct ice_ring *tx_ring, unsigned int size)
{
	if (likely(ICE_DESC_UNUSED(tx_ring) >= size))
		return 0;

	return __ice_maybe_stop_tx(tx_ring, size);
}