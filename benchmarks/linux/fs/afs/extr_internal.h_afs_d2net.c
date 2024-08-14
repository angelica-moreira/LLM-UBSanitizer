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
struct dentry {int /*<<< orphan*/  d_sb; } ;
struct afs_net {int dummy; } ;

/* Variables and functions */
 struct afs_net* afs_sb2net (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct afs_net *afs_d2net(struct dentry *dentry)
{
	return afs_sb2net(dentry->d_sb);
}