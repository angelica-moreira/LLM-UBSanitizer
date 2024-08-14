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
struct vm_area_struct {int vm_flags; int /*<<< orphan*/  vm_page_prot; } ;
struct mtd_info {struct map_info* priv; } ;
struct mtd_file_info {struct mtd_info* mtd; } ;
struct map_info {scalar_t__ phys; int /*<<< orphan*/  size; } ;
struct file {int f_flags; struct mtd_file_info* private_data; } ;

/* Variables and functions */
 int EACCES ; 
 int ENODEV ; 
 int O_DSYNC ; 
 int VM_SHARED ; 
 scalar_t__ __pa (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  high_memory ; 
 int /*<<< orphan*/  pgprot_noncached (int /*<<< orphan*/ ) ; 
 int vm_iomap_memory (struct vm_area_struct*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mtdchar_mmap(struct file *file, struct vm_area_struct *vma)
{
#ifdef CONFIG_MMU
	struct mtd_file_info *mfi = file->private_data;
	struct mtd_info *mtd = mfi->mtd;
	struct map_info *map = mtd->priv;

        /* This is broken because it assumes the MTD device is map-based
	   and that mtd->priv is a valid struct map_info.  It should be
	   replaced with something that uses the mtd_get_unmapped_area()
	   operation properly. */
	if (0 /*mtd->type == MTD_RAM || mtd->type == MTD_ROM*/) {
#ifdef pgprot_noncached
		if (file->f_flags & O_DSYNC || map->phys >= __pa(high_memory))
			vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
#endif
		return vm_iomap_memory(vma, map->phys, map->size);
	}
	return -ENODEV;
#else
	return vma->vm_flags & VM_SHARED ? 0 : -EACCES;
#endif
}