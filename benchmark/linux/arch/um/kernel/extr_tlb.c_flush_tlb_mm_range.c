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
struct mm_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fix_range (struct mm_struct*,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 

void flush_tlb_mm_range(struct mm_struct *mm, unsigned long start,
			unsigned long end)
{
	fix_range(mm, start, end, 0);
}