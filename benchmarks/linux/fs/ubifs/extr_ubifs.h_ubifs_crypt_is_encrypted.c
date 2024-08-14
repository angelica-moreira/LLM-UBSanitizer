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
struct ubifs_inode {int flags; } ;
struct inode {int dummy; } ;

/* Variables and functions */
 int UBIFS_CRYPT_FL ; 
 struct ubifs_inode* ubifs_inode (struct inode const*) ; 

__attribute__((used)) static inline bool ubifs_crypt_is_encrypted(const struct inode *inode)
{
	const struct ubifs_inode *ui = ubifs_inode(inode);

	return ui->flags & UBIFS_CRYPT_FL;
}