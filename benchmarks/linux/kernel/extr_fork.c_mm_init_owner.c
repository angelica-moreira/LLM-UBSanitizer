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
struct task_struct {int dummy; } ;
struct mm_struct {struct task_struct* owner; } ;

/* Variables and functions */

__attribute__((used)) static void mm_init_owner(struct mm_struct *mm, struct task_struct *p)
{
#ifdef CONFIG_MEMCG
	mm->owner = p;
#endif
}