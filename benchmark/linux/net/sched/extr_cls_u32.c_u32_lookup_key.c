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
typedef  scalar_t__ u32 ;
struct tc_u_knode {scalar_t__ handle; int /*<<< orphan*/  next; } ;
struct tc_u_hnode {unsigned int divisor; int /*<<< orphan*/ * ht; } ;

/* Variables and functions */
 unsigned int TC_U32_HASH (scalar_t__) ; 
 struct tc_u_knode* rtnl_dereference (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct tc_u_knode *u32_lookup_key(struct tc_u_hnode *ht, u32 handle)
{
	unsigned int sel;
	struct tc_u_knode *n = NULL;

	sel = TC_U32_HASH(handle);
	if (sel > ht->divisor)
		goto out;

	for (n = rtnl_dereference(ht->ht[sel]);
	     n;
	     n = rtnl_dereference(n->next))
		if (n->handle == handle)
			break;
out:
	return n;
}