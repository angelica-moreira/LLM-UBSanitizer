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
struct nfp_repr {int /*<<< orphan*/  netdev; int /*<<< orphan*/  stats; } ;

/* Variables and functions */
 int /*<<< orphan*/  free_netdev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_percpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void __nfp_repr_free(struct nfp_repr *repr)
{
	free_percpu(repr->stats);
	free_netdev(repr->netdev);
}