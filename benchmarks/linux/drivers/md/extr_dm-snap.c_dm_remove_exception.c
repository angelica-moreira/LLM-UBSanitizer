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
struct dm_exception {int /*<<< orphan*/  hash_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  hlist_bl_del (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void dm_remove_exception(struct dm_exception *e)
{
	hlist_bl_del(&e->hash_list);
}