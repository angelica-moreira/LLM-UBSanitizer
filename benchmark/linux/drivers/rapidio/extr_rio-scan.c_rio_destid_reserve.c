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
typedef  int /*<<< orphan*/  u16 ;
struct rio_net {scalar_t__ enum_data; } ;
struct rio_id_table {int /*<<< orphan*/  lock; int /*<<< orphan*/  table; scalar_t__ start; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rio_destid_reserve(struct rio_net *net, u16 destid)
{
	int oldbit;
	struct rio_id_table *idtab = (struct rio_id_table *)net->enum_data;

	destid -= idtab->start;
	spin_lock(&idtab->lock);
	oldbit = test_and_set_bit(destid, idtab->table);
	spin_unlock(&idtab->lock);
	return oldbit;
}