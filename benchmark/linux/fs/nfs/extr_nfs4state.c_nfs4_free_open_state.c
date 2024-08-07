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
struct nfs4_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree_rcu (struct nfs4_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_head ; 

__attribute__((used)) static void
nfs4_free_open_state(struct nfs4_state *state)
{
	kfree_rcu(state, rcu_head);
}