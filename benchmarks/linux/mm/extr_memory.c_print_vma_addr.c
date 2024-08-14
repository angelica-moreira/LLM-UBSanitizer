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
struct vm_area_struct {scalar_t__ vm_start; scalar_t__ vm_end; struct file* vm_file; } ;
struct mm_struct {int /*<<< orphan*/  mmap_sem; } ;
struct file {int dummy; } ;
struct TYPE_2__ {struct mm_struct* mm; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_NOWAIT ; 
 scalar_t__ IS_ERR (char*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 scalar_t__ __get_free_page (int /*<<< orphan*/ ) ; 
 TYPE_1__* current ; 
 int /*<<< orphan*/  down_read_trylock (int /*<<< orphan*/ *) ; 
 char* file_path (struct file*,char*,int /*<<< orphan*/ ) ; 
 struct vm_area_struct* find_vma (struct mm_struct*,unsigned long) ; 
 int /*<<< orphan*/  free_page (unsigned long) ; 
 int /*<<< orphan*/  kbasename (char*) ; 
 int /*<<< orphan*/  printk (char*,char*,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 

void print_vma_addr(char *prefix, unsigned long ip)
{
	struct mm_struct *mm = current->mm;
	struct vm_area_struct *vma;

	/*
	 * we might be running from an atomic context so we cannot sleep
	 */
	if (!down_read_trylock(&mm->mmap_sem))
		return;

	vma = find_vma(mm, ip);
	if (vma && vma->vm_file) {
		struct file *f = vma->vm_file;
		char *buf = (char *)__get_free_page(GFP_NOWAIT);
		if (buf) {
			char *p;

			p = file_path(f, buf, PAGE_SIZE);
			if (IS_ERR(p))
				p = "?";
			printk("%s%s[%lx+%lx]", prefix, kbasename(p),
					vma->vm_start,
					vma->vm_end - vma->vm_start);
			free_page((unsigned long)buf);
		}
	}
	up_read(&mm->mmap_sem);
}