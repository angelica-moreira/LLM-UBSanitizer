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
struct net {int dummy; } ;
struct cache_detail {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  remove_cache_proc_entries (struct cache_detail*) ; 
 int /*<<< orphan*/  sunrpc_destroy_cache_detail (struct cache_detail*) ; 

void cache_unregister_net(struct cache_detail *cd, struct net *net)
{
	remove_cache_proc_entries(cd);
	sunrpc_destroy_cache_detail(cd);
}