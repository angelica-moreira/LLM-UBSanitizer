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
struct posix_acl {int dummy; } ;
struct inode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 struct posix_acl* ERR_PTR (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct posix_acl *bad_inode_get_acl(struct inode *inode, int type)
{
	return ERR_PTR(-EIO);
}