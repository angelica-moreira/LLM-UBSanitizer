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
struct scatterlist {int dummy; } ;
struct intel_remapped_info {TYPE_1__* plane; } ;
struct drm_i915_gem_object {int dummy; } ;
typedef  scalar_t__ dma_addr_t ;
struct TYPE_2__ {unsigned int height; unsigned int width; } ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 struct scatterlist* ERR_PTR (int /*<<< orphan*/ ) ; 
 unsigned int PAGE_SIZE ; 
 scalar_t__ i915_gem_object_get_dma_address (struct drm_i915_gem_object*,unsigned long) ; 
 int /*<<< orphan*/  pr_err (char*,unsigned int,unsigned int,unsigned long,...) ; 
 unsigned long remapped_index (struct intel_remapped_info const*,unsigned int,unsigned int,unsigned int) ; 
 scalar_t__ sg_dma_address (struct scatterlist*) ; 
 unsigned int sg_dma_len (struct scatterlist*) ; 
 struct scatterlist* sg_next (struct scatterlist*) ; 

__attribute__((used)) static struct scatterlist *
assert_remapped(struct drm_i915_gem_object *obj,
		const struct intel_remapped_info *r, unsigned int n,
		struct scatterlist *sg)
{
	unsigned int x, y;
	unsigned int left = 0;
	unsigned int offset;

	for (y = 0; y < r->plane[n].height; y++) {
		for (x = 0; x < r->plane[n].width; x++) {
			unsigned long src_idx;
			dma_addr_t src;

			if (!sg) {
				pr_err("Invalid sg table: too short at plane %d, (%d, %d)!\n",
				       n, x, y);
				return ERR_PTR(-EINVAL);
			}
			if (!left) {
				offset = 0;
				left = sg_dma_len(sg);
			}

			src_idx = remapped_index(r, n, x, y);
			src = i915_gem_object_get_dma_address(obj, src_idx);

			if (left < PAGE_SIZE || left & (PAGE_SIZE-1)) {
				pr_err("Invalid sg.length, found %d, expected %lu for remapped page (%d, %d) [src index %lu]\n",
				       sg_dma_len(sg), PAGE_SIZE,
				       x, y, src_idx);
				return ERR_PTR(-EINVAL);
			}

			if (sg_dma_address(sg) + offset != src) {
				pr_err("Invalid address for remapped page (%d, %d) [src index %lu]\n",
				       x, y, src_idx);
				return ERR_PTR(-EINVAL);
			}

			left -= PAGE_SIZE;
			offset += PAGE_SIZE;


			if (!left)
				sg = sg_next(sg);
		}
	}

	return sg;
}