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
typedef  int /*<<< orphan*/  u32 ;
struct vxge_hw_ring_rxd_1 {int /*<<< orphan*/  control_1; int /*<<< orphan*/  buffer0_ptr; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  VXGE_HW_RING_RXD_1_BUFFER0_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VXGE_HW_RING_RXD_1_BUFFER0_SIZE_MASK ; 

__attribute__((used)) static inline
void vxge_hw_ring_rxd_1b_set(
	void *rxdh,
	dma_addr_t dma_pointer,
	u32 size)
{
	struct vxge_hw_ring_rxd_1 *rxdp = (struct vxge_hw_ring_rxd_1 *)rxdh;
	rxdp->buffer0_ptr = dma_pointer;
	rxdp->control_1	&= ~VXGE_HW_RING_RXD_1_BUFFER0_SIZE_MASK;
	rxdp->control_1	|= VXGE_HW_RING_RXD_1_BUFFER0_SIZE(size);
}