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
struct page {struct page* next; int /*<<< orphan*/  inuse; scalar_t__ frozen; int /*<<< orphan*/  freelist; int /*<<< orphan*/  counters; } ;
struct kmem_cache_node {scalar_t__ nr_partial; int /*<<< orphan*/  list_lock; } ;
struct kmem_cache_cpu {struct page* partial; } ;
struct kmem_cache {scalar_t__ min_partial; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEACTIVATE_EMPTY ; 
 int /*<<< orphan*/  DEACTIVATE_TO_TAIL ; 
 int /*<<< orphan*/  FREE_ADD_PARTIAL ; 
 int /*<<< orphan*/  FREE_SLAB ; 
 int /*<<< orphan*/  VM_BUG_ON (int) ; 
 int /*<<< orphan*/  __cmpxchg_double_slab (struct kmem_cache*,struct page*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  add_partial (struct kmem_cache_node*,struct page*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  discard_slab (struct kmem_cache*,struct page*) ; 
 struct kmem_cache_node* get_node (struct kmem_cache*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  page_to_nid (struct page*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stat (struct kmem_cache*,int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void unfreeze_partials(struct kmem_cache *s,
		struct kmem_cache_cpu *c)
{
#ifdef CONFIG_SLUB_CPU_PARTIAL
	struct kmem_cache_node *n = NULL, *n2 = NULL;
	struct page *page, *discard_page = NULL;

	while ((page = c->partial)) {
		struct page new;
		struct page old;

		c->partial = page->next;

		n2 = get_node(s, page_to_nid(page));
		if (n != n2) {
			if (n)
				spin_unlock(&n->list_lock);

			n = n2;
			spin_lock(&n->list_lock);
		}

		do {

			old.freelist = page->freelist;
			old.counters = page->counters;
			VM_BUG_ON(!old.frozen);

			new.counters = old.counters;
			new.freelist = old.freelist;

			new.frozen = 0;

		} while (!__cmpxchg_double_slab(s, page,
				old.freelist, old.counters,
				new.freelist, new.counters,
				"unfreezing slab"));

		if (unlikely(!new.inuse && n->nr_partial >= s->min_partial)) {
			page->next = discard_page;
			discard_page = page;
		} else {
			add_partial(n, page, DEACTIVATE_TO_TAIL);
			stat(s, FREE_ADD_PARTIAL);
		}
	}

	if (n)
		spin_unlock(&n->list_lock);

	while (discard_page) {
		page = discard_page;
		discard_page = discard_page->next;

		stat(s, DEACTIVATE_EMPTY);
		discard_slab(s, page);
		stat(s, FREE_SLAB);
	}
#endif	/* CONFIG_SLUB_CPU_PARTIAL */
}