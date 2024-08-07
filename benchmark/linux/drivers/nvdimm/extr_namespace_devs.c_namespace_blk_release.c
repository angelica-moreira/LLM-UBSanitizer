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
struct nd_region {int /*<<< orphan*/  ns_ida; } ;
struct nd_namespace_blk {scalar_t__ id; struct nd_namespace_blk* res; struct nd_namespace_blk* uuid; struct nd_namespace_blk* alt_name; } ;
struct device {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  ida_simple_remove (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct nd_namespace_blk*) ; 
 struct nd_namespace_blk* to_nd_namespace_blk (struct device*) ; 
 struct nd_region* to_nd_region (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void namespace_blk_release(struct device *dev)
{
	struct nd_namespace_blk *nsblk = to_nd_namespace_blk(dev);
	struct nd_region *nd_region = to_nd_region(dev->parent);

	if (nsblk->id >= 0)
		ida_simple_remove(&nd_region->ns_ida, nsblk->id);
	kfree(nsblk->alt_name);
	kfree(nsblk->uuid);
	kfree(nsblk->res);
	kfree(nsblk);
}