#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct parman_prio {int dummy; } ;
struct parman_item {int /*<<< orphan*/  index; } ;
struct parman {int /*<<< orphan*/  priv; TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* move ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long,unsigned long) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long,unsigned long) ; 

__attribute__((used)) static void __parman_prio_move(struct parman *parman, struct parman_prio *prio,
			       struct parman_item *item, unsigned long to_index,
			       unsigned long count)
{
	parman->ops->move(parman->priv, item->index, to_index, count);
}