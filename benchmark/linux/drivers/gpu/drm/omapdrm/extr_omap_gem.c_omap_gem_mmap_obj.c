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
struct vm_area_struct {int /*<<< orphan*/  vm_flags; int /*<<< orphan*/  vm_page_prot; int /*<<< orphan*/  vm_file; scalar_t__ vm_pgoff; } ;
struct omap_gem_object {int flags; } ;
struct drm_gem_object {int /*<<< orphan*/  filp; } ;

/* Variables and functions */
 int EINVAL ; 
 int OMAP_BO_UNCACHED ; 
 int OMAP_BO_WC ; 
 int /*<<< orphan*/  VM_MIXEDMAP ; 
 int /*<<< orphan*/  VM_PFNMAP ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  fput (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_file (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgprot_noncached (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pgprot_writecombine (int /*<<< orphan*/ ) ; 
 struct omap_gem_object* to_omap_bo (struct drm_gem_object*) ; 
 int /*<<< orphan*/  vm_get_page_prot (int /*<<< orphan*/ ) ; 

int omap_gem_mmap_obj(struct drm_gem_object *obj,
		struct vm_area_struct *vma)
{
	struct omap_gem_object *omap_obj = to_omap_bo(obj);

	vma->vm_flags &= ~VM_PFNMAP;
	vma->vm_flags |= VM_MIXEDMAP;

	if (omap_obj->flags & OMAP_BO_WC) {
		vma->vm_page_prot = pgprot_writecombine(vm_get_page_prot(vma->vm_flags));
	} else if (omap_obj->flags & OMAP_BO_UNCACHED) {
		vma->vm_page_prot = pgprot_noncached(vm_get_page_prot(vma->vm_flags));
	} else {
		/*
		 * We do have some private objects, at least for scanout buffers
		 * on hardware without DMM/TILER.  But these are allocated write-
		 * combine
		 */
		if (WARN_ON(!obj->filp))
			return -EINVAL;

		/*
		 * Shunt off cached objs to shmem file so they have their own
		 * address_space (so unmap_mapping_range does what we want,
		 * in particular in the case of mmap'd dmabufs)
		 */
		fput(vma->vm_file);
		vma->vm_pgoff = 0;
		vma->vm_file  = get_file(obj->filp);

		vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);
	}

	return 0;
}