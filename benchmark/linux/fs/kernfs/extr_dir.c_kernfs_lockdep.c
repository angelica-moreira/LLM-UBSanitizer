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
struct kernfs_node {int flags; } ;

/* Variables and functions */
 int KERNFS_LOCKDEP ; 

__attribute__((used)) static bool kernfs_lockdep(struct kernfs_node *kn)
{
#ifdef CONFIG_DEBUG_LOCK_ALLOC
	return kn->flags & KERNFS_LOCKDEP;
#else
	return false;
#endif
}