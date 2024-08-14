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
struct hpfs_sb_info {struct hpfs_sb_info* sb_bmp_dir; struct hpfs_sb_info* sb_cp_table; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct hpfs_sb_info*) ; 

__attribute__((used)) static void free_sbi(struct hpfs_sb_info *sbi)
{
	kfree(sbi->sb_cp_table);
	kfree(sbi->sb_bmp_dir);
	kfree(sbi);
}