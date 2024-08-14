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
struct btrfs_trans_handle {int dummy; } ;
struct btrfs_root {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BTRFS_RESERVE_FLUSH_ALL ; 
 int /*<<< orphan*/  TRANS_START ; 
 struct btrfs_trans_handle* start_transaction (struct btrfs_root*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

struct btrfs_trans_handle *btrfs_start_transaction(struct btrfs_root *root,
						   unsigned int num_items)
{
	return start_transaction(root, num_items, TRANS_START,
				 BTRFS_RESERVE_FLUSH_ALL, true);
}