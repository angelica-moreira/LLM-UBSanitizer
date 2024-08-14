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
typedef  int uint32_t ;
struct vmw_stdu_update {int dummy; } ;
struct vmw_stdu_dma {int dummy; } ;
struct vmw_du_update_plane {int dummy; } ;
typedef  int /*<<< orphan*/  SVGA3dCopyBox ;
typedef  int /*<<< orphan*/  SVGA3dCmdSurfaceDMASuffix ;

/* Variables and functions */

__attribute__((used)) static uint32_t vmw_stdu_bo_fifo_size(struct vmw_du_update_plane *update,
				      uint32_t num_hits)
{
	return sizeof(struct vmw_stdu_dma) + sizeof(SVGA3dCopyBox) * num_hits +
		sizeof(SVGA3dCmdSurfaceDMASuffix) +
		sizeof(struct vmw_stdu_update);
}