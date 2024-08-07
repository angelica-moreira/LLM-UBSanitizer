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
struct klist_node {int dummy; } ;
struct device_private {struct device* device; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  get_device (struct device*) ; 
 struct device_private* to_device_private_parent (struct klist_node*) ; 

__attribute__((used)) static void klist_children_get(struct klist_node *n)
{
	struct device_private *p = to_device_private_parent(n);
	struct device *dev = p->device;

	get_device(dev);
}