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
struct super_block {TYPE_1__* dq_op; } ;
struct dquot {int /*<<< orphan*/  dq_dqb_lock; int /*<<< orphan*/  dq_count; int /*<<< orphan*/  dq_id; struct super_block* dq_sb; int /*<<< orphan*/  dq_dirty; int /*<<< orphan*/  dq_hash; int /*<<< orphan*/  dq_inuse; int /*<<< orphan*/  dq_free; int /*<<< orphan*/  dq_lock; } ;
struct TYPE_2__ {struct dquot* (* alloc_dquot ) (struct super_block*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_HLIST_NODE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  make_kqid_invalid (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 struct dquot* stub1 (struct super_block*,int) ; 

__attribute__((used)) static struct dquot *get_empty_dquot(struct super_block *sb, int type)
{
	struct dquot *dquot;

	dquot = sb->dq_op->alloc_dquot(sb, type);
	if(!dquot)
		return NULL;

	mutex_init(&dquot->dq_lock);
	INIT_LIST_HEAD(&dquot->dq_free);
	INIT_LIST_HEAD(&dquot->dq_inuse);
	INIT_HLIST_NODE(&dquot->dq_hash);
	INIT_LIST_HEAD(&dquot->dq_dirty);
	dquot->dq_sb = sb;
	dquot->dq_id = make_kqid_invalid(type);
	atomic_set(&dquot->dq_count, 1);
	spin_lock_init(&dquot->dq_dqb_lock);

	return dquot;
}