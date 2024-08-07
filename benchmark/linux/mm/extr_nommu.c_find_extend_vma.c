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
struct vm_area_struct {int dummy; } ;
struct mm_struct {int dummy; } ;

/* Variables and functions */
 struct vm_area_struct* find_vma (struct mm_struct*,unsigned long) ; 

struct vm_area_struct *find_extend_vma(struct mm_struct *mm, unsigned long addr)
{
	return find_vma(mm, addr);
}