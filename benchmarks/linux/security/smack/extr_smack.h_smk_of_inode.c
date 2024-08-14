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
struct smack_known {int dummy; } ;
struct inode_smack {struct smack_known* smk_inode; } ;
struct inode {int dummy; } ;

/* Variables and functions */
 struct inode_smack* smack_inode (struct inode const*) ; 

__attribute__((used)) static inline struct smack_known *smk_of_inode(const struct inode *isp)
{
	struct inode_smack *sip = smack_inode(isp);
	return sip->smk_inode;
}