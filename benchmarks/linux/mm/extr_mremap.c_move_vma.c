#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct vm_userfaultfd_ctx {int dummy; } ;
struct vm_area_struct {unsigned long vm_flags; unsigned long vm_pgoff; unsigned long vm_start; unsigned long vm_end; TYPE_2__* vm_next; TYPE_1__* vm_ops; struct mm_struct* vm_mm; } ;
struct mm_struct {int map_count; unsigned long hiwater_vm; unsigned long locked_vm; } ;
struct list_head {int dummy; } ;
struct TYPE_4__ {unsigned long vm_flags; } ;
struct TYPE_3__ {int (* mremap ) (struct vm_area_struct*) ;} ;

/* Variables and functions */
 unsigned long ENOMEM ; 
 int /*<<< orphan*/  MADV_UNMERGEABLE ; 
 unsigned long PAGE_SHIFT ; 
 unsigned long VM_ACCOUNT ; 
 unsigned long VM_LOCKED ; 
 int VM_PFNMAP ; 
 int /*<<< orphan*/  arch_remap (struct mm_struct*,unsigned long,unsigned long,unsigned long,unsigned long) ; 
 struct vm_area_struct* copy_vma (struct vm_area_struct**,unsigned long,unsigned long,unsigned long,int*) ; 
 scalar_t__ do_munmap (struct mm_struct*,unsigned long,unsigned long,struct list_head*) ; 
 int ksm_madvise (struct vm_area_struct*,unsigned long,unsigned long,int /*<<< orphan*/ ,unsigned long*) ; 
 unsigned long move_page_tables (struct vm_area_struct*,unsigned long,struct vm_area_struct*,unsigned long,unsigned long,int) ; 
 int /*<<< orphan*/  mremap_userfaultfd_prep (struct vm_area_struct*,struct vm_userfaultfd_ctx*) ; 
 int stub1 (struct vm_area_struct*) ; 
 int sysctl_max_map_count ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  untrack_pfn_moved (struct vm_area_struct*) ; 
 int /*<<< orphan*/  vm_stat_account (struct mm_struct*,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  vm_unacct_memory (unsigned long) ; 

__attribute__((used)) static unsigned long move_vma(struct vm_area_struct *vma,
		unsigned long old_addr, unsigned long old_len,
		unsigned long new_len, unsigned long new_addr,
		bool *locked, struct vm_userfaultfd_ctx *uf,
		struct list_head *uf_unmap)
{
	struct mm_struct *mm = vma->vm_mm;
	struct vm_area_struct *new_vma;
	unsigned long vm_flags = vma->vm_flags;
	unsigned long new_pgoff;
	unsigned long moved_len;
	unsigned long excess = 0;
	unsigned long hiwater_vm;
	int split = 0;
	int err;
	bool need_rmap_locks;

	/*
	 * We'd prefer to avoid failure later on in do_munmap:
	 * which may split one vma into three before unmapping.
	 */
	if (mm->map_count >= sysctl_max_map_count - 3)
		return -ENOMEM;

	/*
	 * Advise KSM to break any KSM pages in the area to be moved:
	 * it would be confusing if they were to turn up at the new
	 * location, where they happen to coincide with different KSM
	 * pages recently unmapped.  But leave vma->vm_flags as it was,
	 * so KSM can come around to merge on vma and new_vma afterwards.
	 */
	err = ksm_madvise(vma, old_addr, old_addr + old_len,
						MADV_UNMERGEABLE, &vm_flags);
	if (err)
		return err;

	new_pgoff = vma->vm_pgoff + ((old_addr - vma->vm_start) >> PAGE_SHIFT);
	new_vma = copy_vma(&vma, new_addr, new_len, new_pgoff,
			   &need_rmap_locks);
	if (!new_vma)
		return -ENOMEM;

	moved_len = move_page_tables(vma, old_addr, new_vma, new_addr, old_len,
				     need_rmap_locks);
	if (moved_len < old_len) {
		err = -ENOMEM;
	} else if (vma->vm_ops && vma->vm_ops->mremap) {
		err = vma->vm_ops->mremap(new_vma);
	}

	if (unlikely(err)) {
		/*
		 * On error, move entries back from new area to old,
		 * which will succeed since page tables still there,
		 * and then proceed to unmap new area instead of old.
		 */
		move_page_tables(new_vma, new_addr, vma, old_addr, moved_len,
				 true);
		vma = new_vma;
		old_len = new_len;
		old_addr = new_addr;
		new_addr = err;
	} else {
		mremap_userfaultfd_prep(new_vma, uf);
		arch_remap(mm, old_addr, old_addr + old_len,
			   new_addr, new_addr + new_len);
	}

	/* Conceal VM_ACCOUNT so old reservation is not undone */
	if (vm_flags & VM_ACCOUNT) {
		vma->vm_flags &= ~VM_ACCOUNT;
		excess = vma->vm_end - vma->vm_start - old_len;
		if (old_addr > vma->vm_start &&
		    old_addr + old_len < vma->vm_end)
			split = 1;
	}

	/*
	 * If we failed to move page tables we still do total_vm increment
	 * since do_munmap() will decrement it by old_len == new_len.
	 *
	 * Since total_vm is about to be raised artificially high for a
	 * moment, we need to restore high watermark afterwards: if stats
	 * are taken meanwhile, total_vm and hiwater_vm appear too high.
	 * If this were a serious issue, we'd add a flag to do_munmap().
	 */
	hiwater_vm = mm->hiwater_vm;
	vm_stat_account(mm, vma->vm_flags, new_len >> PAGE_SHIFT);

	/* Tell pfnmap has moved from this vma */
	if (unlikely(vma->vm_flags & VM_PFNMAP))
		untrack_pfn_moved(vma);

	if (do_munmap(mm, old_addr, old_len, uf_unmap) < 0) {
		/* OOM: unable to split vma, just get accounts right */
		vm_unacct_memory(excess >> PAGE_SHIFT);
		excess = 0;
	}
	mm->hiwater_vm = hiwater_vm;

	/* Restore VM_ACCOUNT if one or two pieces of vma left */
	if (excess) {
		vma->vm_flags |= VM_ACCOUNT;
		if (split)
			vma->vm_next->vm_flags |= VM_ACCOUNT;
	}

	if (vm_flags & VM_LOCKED) {
		mm->locked_vm += new_len >> PAGE_SHIFT;
		*locked = true;
	}

	return new_addr;
}