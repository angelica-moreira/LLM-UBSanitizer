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
struct inode {int /*<<< orphan*/  i_mode; } ;

/* Variables and functions */
#define  ACL_TYPE_ACCESS 129 
#define  ACL_TYPE_DEFAULT 128 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct posix_acl*) ; 
 int PTR_ERR (struct posix_acl*) ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 int __nfs3_proc_setacls (struct inode*,struct posix_acl*,struct posix_acl*) ; 
 struct posix_acl* get_acl (struct inode*,int const) ; 
 struct posix_acl* posix_acl_from_mode (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  posix_acl_release (struct posix_acl*) ; 

int nfs3_set_acl(struct inode *inode, struct posix_acl *acl, int type)
{
	struct posix_acl *alloc = NULL, *dfacl = NULL;
	int status;

	if (S_ISDIR(inode->i_mode)) {
		switch(type) {
		case ACL_TYPE_ACCESS:
			alloc = dfacl = get_acl(inode, ACL_TYPE_DEFAULT);
			if (IS_ERR(alloc))
				goto fail;
			break;

		case ACL_TYPE_DEFAULT:
			dfacl = acl;
			alloc = acl = get_acl(inode, ACL_TYPE_ACCESS);
			if (IS_ERR(alloc))
				goto fail;
			break;
		}
	}

	if (acl == NULL) {
		alloc = acl = posix_acl_from_mode(inode->i_mode, GFP_KERNEL);
		if (IS_ERR(alloc))
			goto fail;
	}
	status = __nfs3_proc_setacls(inode, acl, dfacl);
	posix_acl_release(alloc);
	return status;

fail:
	return PTR_ERR(alloc);
}