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
typedef  int /*<<< orphan*/  u32 ;
struct psample_group {int /*<<< orphan*/  refcount; } ;
struct net {int dummy; } ;

/* Variables and functions */
 struct psample_group* psample_group_create (struct net*,int /*<<< orphan*/ ) ; 
 struct psample_group* psample_group_lookup (struct net*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  psample_groups_lock ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

struct psample_group *psample_group_get(struct net *net, u32 group_num)
{
	struct psample_group *group;

	spin_lock_bh(&psample_groups_lock);

	group = psample_group_lookup(net, group_num);
	if (!group) {
		group = psample_group_create(net, group_num);
		if (!group)
			goto out;
	}
	group->refcount++;

out:
	spin_unlock_bh(&psample_groups_lock);
	return group;
}