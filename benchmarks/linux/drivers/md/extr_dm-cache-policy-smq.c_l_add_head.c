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
struct ilist {int /*<<< orphan*/  nr_elts; void* tail; void* head; } ;
struct entry_space {int dummy; } ;
struct entry {int /*<<< orphan*/  sentinel; void* prev; void* next; } ;

/* Variables and functions */
 void* INDEXER_NULL ; 
 struct entry* l_head (struct entry_space*,struct ilist*) ; 
 void* to_index (struct entry_space*,struct entry*) ; 

__attribute__((used)) static void l_add_head(struct entry_space *es, struct ilist *l, struct entry *e)
{
	struct entry *head = l_head(es, l);

	e->next = l->head;
	e->prev = INDEXER_NULL;

	if (head)
		head->prev = l->head = to_index(es, e);
	else
		l->head = l->tail = to_index(es, e);

	if (!e->sentinel)
		l->nr_elts++;
}