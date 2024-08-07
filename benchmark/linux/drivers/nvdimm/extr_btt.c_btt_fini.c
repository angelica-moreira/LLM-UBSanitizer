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
struct btt {int /*<<< orphan*/  debugfs_dir; } ;

/* Variables and functions */
 int /*<<< orphan*/  btt_blk_cleanup (struct btt*) ; 
 int /*<<< orphan*/  debugfs_remove_recursive (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_arenas (struct btt*) ; 

__attribute__((used)) static void btt_fini(struct btt *btt)
{
	if (btt) {
		btt_blk_cleanup(btt);
		free_arenas(btt);
		debugfs_remove_recursive(btt->debugfs_dir);
	}
}