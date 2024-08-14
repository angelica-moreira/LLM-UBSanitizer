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
struct tipc_discoverer {int /*<<< orphan*/  lock; int /*<<< orphan*/  num_nodes; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

void tipc_disc_add_dest(struct tipc_discoverer *d)
{
	spin_lock_bh(&d->lock);
	d->num_nodes++;
	spin_unlock_bh(&d->lock);
}