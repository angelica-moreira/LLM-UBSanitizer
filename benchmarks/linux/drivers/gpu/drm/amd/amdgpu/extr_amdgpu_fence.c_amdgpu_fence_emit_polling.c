#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct TYPE_2__ {int /*<<< orphan*/  gpu_addr; scalar_t__ sync_seq; } ;
struct amdgpu_ring {TYPE_1__ fence_drv; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  amdgpu_ring_emit_fence (struct amdgpu_ring*,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 

int amdgpu_fence_emit_polling(struct amdgpu_ring *ring, uint32_t *s)
{
	uint32_t seq;

	if (!s)
		return -EINVAL;

	seq = ++ring->fence_drv.sync_seq;
	amdgpu_ring_emit_fence(ring, ring->fence_drv.gpu_addr,
			       seq, 0);

	*s = seq;

	return 0;
}