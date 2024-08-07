#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct path {scalar_t__ mnt; int /*<<< orphan*/  dentry; } ;
struct TYPE_2__ {scalar_t__ mnt; int /*<<< orphan*/  dentry; } ;
struct nameidata {int flags; TYPE_1__ path; } ;

/* Variables and functions */
 int LOOKUP_RCU ; 
 int /*<<< orphan*/  dput (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mntput (scalar_t__) ; 

__attribute__((used)) static inline void path_to_nameidata(const struct path *path,
					struct nameidata *nd)
{
	if (!(nd->flags & LOOKUP_RCU)) {
		dput(nd->path.dentry);
		if (nd->path.mnt != path->mnt)
			mntput(nd->path.mnt);
	}
	nd->path.mnt = path->mnt;
	nd->path.dentry = path->dentry;
}