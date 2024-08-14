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
struct ntb_msit_ctx {int /*<<< orphan*/  dbgfs_dir; } ;

/* Variables and functions */
 int /*<<< orphan*/  debugfs_remove_recursive (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ntb_msit_remove_dbgfs(struct ntb_msit_ctx *nm)
{
	debugfs_remove_recursive(nm->dbgfs_dir);
}