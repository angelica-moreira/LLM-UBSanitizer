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
struct net {int /*<<< orphan*/  proc_net; } ;

/* Variables and functions */
 int /*<<< orphan*/  remove_proc_entry (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void exp_proc_remove(struct net *net)
{
#ifdef CONFIG_NF_CONNTRACK_PROCFS
	remove_proc_entry("nf_conntrack_expect", net->proc_net);
#endif /* CONFIG_NF_CONNTRACK_PROCFS */
}