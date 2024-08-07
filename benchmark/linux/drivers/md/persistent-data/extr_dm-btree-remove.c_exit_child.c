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
struct dm_btree_info {int /*<<< orphan*/  tm; } ;
struct child {int /*<<< orphan*/  block; } ;

/* Variables and functions */
 int /*<<< orphan*/  dm_tm_unlock (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void exit_child(struct dm_btree_info *info, struct child *c)
{
	dm_tm_unlock(info->tm, c->block);
}