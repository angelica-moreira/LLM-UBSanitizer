#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_3__* prev; } ;
struct klist_node {TYPE_1__ n_node; int /*<<< orphan*/  n_ref; } ;
struct klist_iter {struct klist_node* i_cur; TYPE_2__* i_klist; } ;
struct TYPE_6__ {struct TYPE_6__* prev; } ;
struct TYPE_5__ {void (* put ) (struct klist_node*) ;int /*<<< orphan*/  k_lock; TYPE_3__ k_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  klist_dec_and_del (struct klist_node*) ; 
 int /*<<< orphan*/  knode_dead (struct klist_node*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct klist_node* to_klist_node (TYPE_3__*) ; 

struct klist_node *klist_prev(struct klist_iter *i)
{
	void (*put)(struct klist_node *) = i->i_klist->put;
	struct klist_node *last = i->i_cur;
	struct klist_node *prev;
	unsigned long flags;

	spin_lock_irqsave(&i->i_klist->k_lock, flags);

	if (last) {
		prev = to_klist_node(last->n_node.prev);
		if (!klist_dec_and_del(last))
			put = NULL;
	} else
		prev = to_klist_node(i->i_klist->k_list.prev);

	i->i_cur = NULL;
	while (prev != to_klist_node(&i->i_klist->k_list)) {
		if (likely(!knode_dead(prev))) {
			kref_get(&prev->n_ref);
			i->i_cur = prev;
			break;
		}
		prev = to_klist_node(prev->n_node.prev);
	}

	spin_unlock_irqrestore(&i->i_klist->k_lock, flags);

	if (put && last)
		put(last);
	return i->i_cur;
}