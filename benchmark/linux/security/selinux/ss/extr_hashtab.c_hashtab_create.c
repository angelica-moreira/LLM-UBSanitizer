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
typedef  size_t u32 ;
struct hashtab {size_t size; size_t (* hash_value ) (struct hashtab*,void const*) ;int (* keycmp ) (struct hashtab*,void const*,void const*) ;int /*<<< orphan*/ ** htable; scalar_t__ nel; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  kfree (struct hashtab*) ; 
 int /*<<< orphan*/ ** kmalloc_array (size_t,int,int /*<<< orphan*/ ) ; 
 struct hashtab* kzalloc (int,int /*<<< orphan*/ ) ; 

struct hashtab *hashtab_create(u32 (*hash_value)(struct hashtab *h, const void *key),
			       int (*keycmp)(struct hashtab *h, const void *key1, const void *key2),
			       u32 size)
{
	struct hashtab *p;
	u32 i;

	p = kzalloc(sizeof(*p), GFP_KERNEL);
	if (!p)
		return p;

	p->size = size;
	p->nel = 0;
	p->hash_value = hash_value;
	p->keycmp = keycmp;
	p->htable = kmalloc_array(size, sizeof(*p->htable), GFP_KERNEL);
	if (!p->htable) {
		kfree(p);
		return NULL;
	}

	for (i = 0; i < size; i++)
		p->htable[i] = NULL;

	return p;
}