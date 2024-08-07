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
struct hnae3_ring_chain_node {struct hnae3_ring_chain_node* next; } ;

/* Variables and functions */
 int /*<<< orphan*/  kzfree (struct hnae3_ring_chain_node*) ; 

__attribute__((used)) static void hclge_free_vector_ring_chain(struct hnae3_ring_chain_node *head)
{
	struct hnae3_ring_chain_node *chain_tmp, *chain;

	chain = head->next;

	while (chain) {
		chain_tmp = chain->next;
		kzfree(chain);
		chain = chain_tmp;
	}
}