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
struct nfs_server {int /*<<< orphan*/  active; } ;

/* Variables and functions */
 struct nfs_server* NFS_SB (struct super_block*) ; 
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  deactivate_super (struct super_block*) ; 

void nfs_sb_deactive(struct super_block *sb)
{
	struct nfs_server *server = NFS_SB(sb);

	if (atomic_dec_and_test(&server->active))
		deactivate_super(sb);
}