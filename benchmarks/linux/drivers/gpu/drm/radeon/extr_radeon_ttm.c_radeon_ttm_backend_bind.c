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
typedef  int uint32_t ;
struct ttm_tt {scalar_t__ caching_state; int /*<<< orphan*/  num_pages; int /*<<< orphan*/  pages; } ;
struct ttm_mem_reg {int start; } ;
struct TYPE_2__ {int /*<<< orphan*/  dma_address; } ;
struct radeon_ttm_tt {unsigned long offset; TYPE_1__ ttm; int /*<<< orphan*/  rdev; scalar_t__ userptr; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_ERROR (char*,int /*<<< orphan*/ ,unsigned int) ; 
 int PAGE_SHIFT ; 
 int RADEON_GART_PAGE_READ ; 
 int RADEON_GART_PAGE_SNOOP ; 
 int RADEON_GART_PAGE_VALID ; 
 int RADEON_GART_PAGE_WRITE ; 
 int /*<<< orphan*/  WARN (int,char*,int /*<<< orphan*/ ,struct ttm_mem_reg*,struct ttm_tt*) ; 
 int radeon_gart_bind (int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  radeon_ttm_tt_pin_userptr (struct ttm_tt*) ; 
 scalar_t__ tt_cached ; 

__attribute__((used)) static int radeon_ttm_backend_bind(struct ttm_tt *ttm,
				   struct ttm_mem_reg *bo_mem)
{
	struct radeon_ttm_tt *gtt = (void*)ttm;
	uint32_t flags = RADEON_GART_PAGE_VALID | RADEON_GART_PAGE_READ |
		RADEON_GART_PAGE_WRITE;
	int r;

	if (gtt->userptr) {
		radeon_ttm_tt_pin_userptr(ttm);
		flags &= ~RADEON_GART_PAGE_WRITE;
	}

	gtt->offset = (unsigned long)(bo_mem->start << PAGE_SHIFT);
	if (!ttm->num_pages) {
		WARN(1, "nothing to bind %lu pages for mreg %p back %p!\n",
		     ttm->num_pages, bo_mem, ttm);
	}
	if (ttm->caching_state == tt_cached)
		flags |= RADEON_GART_PAGE_SNOOP;
	r = radeon_gart_bind(gtt->rdev, gtt->offset, ttm->num_pages,
			     ttm->pages, gtt->ttm.dma_address, flags);
	if (r) {
		DRM_ERROR("failed to bind %lu pages at 0x%08X\n",
			  ttm->num_pages, (unsigned)gtt->offset);
		return r;
	}
	return 0;
}