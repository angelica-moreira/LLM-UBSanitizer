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
struct ebitmap_node {unsigned long startbit; struct ebitmap_node* next; } ;
struct ebitmap {unsigned long highbit; struct ebitmap_node* node; } ;

/* Variables and functions */
 unsigned long EBITMAP_SIZE ; 
 int ebitmap_node_get_bit (struct ebitmap_node*,unsigned long) ; 

int ebitmap_get_bit(struct ebitmap *e, unsigned long bit)
{
	struct ebitmap_node *n;

	if (e->highbit < bit)
		return 0;

	n = e->node;
	while (n && (n->startbit <= bit)) {
		if ((n->startbit + EBITMAP_SIZE) > bit)
			return ebitmap_node_get_bit(n, bit);
		n = n->next;
	}

	return 0;
}