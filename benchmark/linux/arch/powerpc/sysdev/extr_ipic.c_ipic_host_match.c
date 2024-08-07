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
struct irq_domain {int dummy; } ;
struct device_node {int dummy; } ;
typedef  enum irq_domain_bus_token { ____Placeholder_irq_domain_bus_token } irq_domain_bus_token ;

/* Variables and functions */
 struct device_node* irq_domain_get_of_node (struct irq_domain*) ; 

__attribute__((used)) static int ipic_host_match(struct irq_domain *h, struct device_node *node,
			   enum irq_domain_bus_token bus_token)
{
	/* Exact match, unless ipic node is NULL */
	struct device_node *of_node = irq_domain_get_of_node(h);
	return of_node == NULL || of_node == node;
}