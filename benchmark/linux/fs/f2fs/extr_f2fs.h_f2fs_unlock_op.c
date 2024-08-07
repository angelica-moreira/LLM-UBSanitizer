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
struct f2fs_sb_info {int /*<<< orphan*/  cp_rwsem; } ;

/* Variables and functions */
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void f2fs_unlock_op(struct f2fs_sb_info *sbi)
{
	up_read(&sbi->cp_rwsem);
}