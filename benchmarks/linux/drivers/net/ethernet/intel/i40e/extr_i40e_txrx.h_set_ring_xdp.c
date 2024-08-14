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
struct i40e_ring {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  I40E_TXR_FLAGS_XDP ; 

__attribute__((used)) static inline void set_ring_xdp(struct i40e_ring *ring)
{
	ring->flags |= I40E_TXR_FLAGS_XDP;
}