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
struct inode {int /*<<< orphan*/ * i_link; int /*<<< orphan*/  i_mode; } ;

/* Variables and functions */
 scalar_t__ IS_ENCRYPTED (struct inode*) ; 
 scalar_t__ S_ISLNK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 

void fscrypt_free_inode(struct inode *inode)
{
	if (IS_ENCRYPTED(inode) && S_ISLNK(inode->i_mode)) {
		kfree(inode->i_link);
		inode->i_link = NULL;
	}
}