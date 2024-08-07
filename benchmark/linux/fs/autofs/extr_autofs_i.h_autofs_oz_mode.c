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
struct autofs_sb_info {int flags; scalar_t__ oz_pgrp; } ;

/* Variables and functions */
 int AUTOFS_SBI_CATATONIC ; 
 int /*<<< orphan*/  current ; 
 scalar_t__ task_pgrp (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int autofs_oz_mode(struct autofs_sb_info *sbi)
{
	return ((sbi->flags & AUTOFS_SBI_CATATONIC) ||
		 task_pgrp(current) == sbi->oz_pgrp);
}