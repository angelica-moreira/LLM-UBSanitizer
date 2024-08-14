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
typedef  int /*<<< orphan*/  u64 ;
struct super_block {int dummy; } ;
typedef  int /*<<< orphan*/  __fs64 ;
typedef  int /*<<< orphan*/  __fs32 ;
struct TYPE_4__ {TYPE_1__* s_uspi; } ;
struct TYPE_3__ {scalar_t__ fs_magic; } ;

/* Variables and functions */
 scalar_t__ UFS2_MAGIC ; 
 TYPE_2__* UFS_SB (struct super_block*) ; 
 int /*<<< orphan*/  fs32_to_cpu (struct super_block*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fs64_to_cpu (struct super_block*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u64 ufs_data_ptr_to_cpu(struct super_block *sb, void *p)
{
	return UFS_SB(sb)->s_uspi->fs_magic == UFS2_MAGIC ?
		fs64_to_cpu(sb, *(__fs64 *)p) :
		fs32_to_cpu(sb, *(__fs32 *)p);
}