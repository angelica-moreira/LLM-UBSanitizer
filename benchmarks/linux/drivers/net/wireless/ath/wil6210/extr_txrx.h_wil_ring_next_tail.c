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
typedef  int u32 ;
struct wil_ring {int swtail; int size; } ;

/* Variables and functions */

__attribute__((used)) static inline u32 wil_ring_next_tail(struct wil_ring *ring)
{
	return (ring->swtail + 1) % ring->size;
}