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
struct TYPE_2__ {int /*<<< orphan*/  rs_node; } ;
struct gfs2_inode {int /*<<< orphan*/  i_iopen_gh; int /*<<< orphan*/ * i_hash_cache; TYPE_1__ i_res; int /*<<< orphan*/  i_rgd_gh; int /*<<< orphan*/ * i_qadata; int /*<<< orphan*/  i_trunc_list; int /*<<< orphan*/  i_rw_mutex; int /*<<< orphan*/  i_sizehint; int /*<<< orphan*/  i_inode; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RB_CLEAR_NODE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gfs2_holder_mark_uninitialized (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  init_rwsem (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  inode_init_once (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void gfs2_init_inode_once(void *foo)
{
	struct gfs2_inode *ip = foo;

	inode_init_once(&ip->i_inode);
	atomic_set(&ip->i_sizehint, 0);
	init_rwsem(&ip->i_rw_mutex);
	INIT_LIST_HEAD(&ip->i_trunc_list);
	ip->i_qadata = NULL;
	gfs2_holder_mark_uninitialized(&ip->i_rgd_gh);
	memset(&ip->i_res, 0, sizeof(ip->i_res));
	RB_CLEAR_NODE(&ip->i_res.rs_node);
	ip->i_hash_cache = NULL;
	gfs2_holder_mark_uninitialized(&ip->i_iopen_gh);
}