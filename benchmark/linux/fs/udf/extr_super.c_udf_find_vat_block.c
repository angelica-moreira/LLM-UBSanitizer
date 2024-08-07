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
struct udf_sb_info {struct inode* s_vat_inode; struct udf_part_map* s_partmaps; } ;
struct udf_part_map {scalar_t__ s_partition_root; } ;
struct super_block {int dummy; } ;
struct kernel_lb_addr {int partitionReferenceNum; scalar_t__ logicalBlockNum; } ;
struct inode {int dummy; } ;
typedef  scalar_t__ sector_t ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR (struct inode*) ; 
 struct udf_sb_info* UDF_SB (struct super_block*) ; 
 struct inode* udf_iget_special (struct super_block*,struct kernel_lb_addr*) ; 

__attribute__((used)) static void udf_find_vat_block(struct super_block *sb, int p_index,
			       int type1_index, sector_t start_block)
{
	struct udf_sb_info *sbi = UDF_SB(sb);
	struct udf_part_map *map = &sbi->s_partmaps[p_index];
	sector_t vat_block;
	struct kernel_lb_addr ino;
	struct inode *inode;

	/*
	 * VAT file entry is in the last recorded block. Some broken disks have
	 * it a few blocks before so try a bit harder...
	 */
	ino.partitionReferenceNum = type1_index;
	for (vat_block = start_block;
	     vat_block >= map->s_partition_root &&
	     vat_block >= start_block - 3; vat_block--) {
		ino.logicalBlockNum = vat_block - map->s_partition_root;
		inode = udf_iget_special(sb, &ino);
		if (!IS_ERR(inode)) {
			sbi->s_vat_inode = inode;
			break;
		}
	}
}