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
struct list_head {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  btrfs_put_workspace (int /*<<< orphan*/ *,struct list_head*) ; 
 int /*<<< orphan*/  wsm ; 

__attribute__((used)) static void zlib_put_workspace(struct list_head *ws)
{
	btrfs_put_workspace(&wsm, ws);
}