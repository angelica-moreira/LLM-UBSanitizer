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
struct ubifs_info {int key_len; int hash_len; } ;

/* Variables and functions */
 int UBIFS_BRANCH_SZ ; 
 int UBIFS_IDX_NODE_SZ ; 

__attribute__((used)) static inline int ubifs_idx_node_sz(const struct ubifs_info *c, int child_cnt)
{
	return UBIFS_IDX_NODE_SZ + (UBIFS_BRANCH_SZ + c->key_len + c->hash_len)
				   * child_cnt;
}