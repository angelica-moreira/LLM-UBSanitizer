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
struct fs_context {int dummy; } ;

/* Variables and functions */
 int get_tree_single (struct fs_context*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xenfs_fill_super ; 

__attribute__((used)) static int xenfs_get_tree(struct fs_context *fc)
{
	return get_tree_single(fc, xenfs_fill_super);
}