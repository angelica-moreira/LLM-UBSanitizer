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
struct send_ctx {int /*<<< orphan*/  cmp_key; int /*<<< orphan*/  right_path; int /*<<< orphan*/  parent_root; int /*<<< orphan*/  left_path; int /*<<< orphan*/  send_root; } ;

/* Variables and functions */
 int /*<<< orphan*/  __record_changed_deleted_ref ; 
 int /*<<< orphan*/  __record_changed_new_ref ; 
 int iterate_inode_ref (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct send_ctx*) ; 

__attribute__((used)) static int record_changed_ref(struct send_ctx *sctx)
{
	int ret = 0;

	ret = iterate_inode_ref(sctx->send_root, sctx->left_path,
			sctx->cmp_key, 0, __record_changed_new_ref, sctx);
	if (ret < 0)
		goto out;
	ret = iterate_inode_ref(sctx->parent_root, sctx->right_path,
			sctx->cmp_key, 0, __record_changed_deleted_ref, sctx);
	if (ret < 0)
		goto out;
	ret = 0;

out:
	return ret;
}