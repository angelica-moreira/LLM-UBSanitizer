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
struct reiserfs_key {int dummy; } ;
struct buffer_head {int dummy; } ;

/* Variables and functions */
 struct reiserfs_key* reiserfs_node_data (struct buffer_head*) ; 

__attribute__((used)) static inline struct reiserfs_key *internal_key(struct buffer_head *bh,
						int item_num)
{
	struct reiserfs_key *key = reiserfs_node_data(bh);

	return &key[item_num];
}