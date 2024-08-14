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
struct proc_fs_context {int /*<<< orphan*/  pid_ns; } ;
struct fs_context {struct proc_fs_context* fs_private; } ;

/* Variables and functions */
 int get_tree_keyed (struct fs_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  proc_fill_super ; 

__attribute__((used)) static int proc_get_tree(struct fs_context *fc)
{
	struct proc_fs_context *ctx = fc->fs_private;

	return get_tree_keyed(fc, proc_fill_super, ctx->pid_ns);
}