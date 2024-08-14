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
struct drm_gem_object {int /*<<< orphan*/  vma_node; struct drm_device* dev; } ;
struct drm_device {int /*<<< orphan*/  vma_offset_manager; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_vma_offset_remove (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void
drm_gem_free_mmap_offset(struct drm_gem_object *obj)
{
	struct drm_device *dev = obj->dev;

	drm_vma_offset_remove(dev->vma_offset_manager, &obj->vma_node);
}