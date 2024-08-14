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
struct super_block {int dummy; } ;
struct mmp_struct {scalar_t__ mmp_checksum; } ;

/* Variables and functions */
 int /*<<< orphan*/  ext4_has_metadata_csum (struct super_block*) ; 
 scalar_t__ ext4_mmp_csum (struct super_block*,struct mmp_struct*) ; 

__attribute__((used)) static int ext4_mmp_csum_verify(struct super_block *sb, struct mmp_struct *mmp)
{
	if (!ext4_has_metadata_csum(sb))
		return 1;

	return mmp->mmp_checksum == ext4_mmp_csum(sb, mmp);
}