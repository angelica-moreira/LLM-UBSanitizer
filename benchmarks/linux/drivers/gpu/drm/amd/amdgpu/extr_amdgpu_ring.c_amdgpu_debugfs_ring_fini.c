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
struct amdgpu_ring {int /*<<< orphan*/  ent; } ;

/* Variables and functions */
 int /*<<< orphan*/  debugfs_remove (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void amdgpu_debugfs_ring_fini(struct amdgpu_ring *ring)
{
#if defined(CONFIG_DEBUG_FS)
	debugfs_remove(ring->ent);
#endif
}