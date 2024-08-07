#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct key_vector {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/ * next; } ;
struct TYPE_4__ {TYPE_1__ rcu; } ;

/* Variables and functions */
 TYPE_2__* tn_info (struct key_vector*) ; 

__attribute__((used)) static inline void tnode_free_init(struct key_vector *tn)
{
	tn_info(tn)->rcu.next = NULL;
}