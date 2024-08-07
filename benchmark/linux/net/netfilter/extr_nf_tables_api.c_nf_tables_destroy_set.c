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
struct nft_set {int /*<<< orphan*/  bindings; } ;
struct nft_ctx {int dummy; } ;

/* Variables and functions */
 scalar_t__ list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nft_set_destroy (struct nft_set*) ; 
 scalar_t__ nft_set_is_anonymous (struct nft_set*) ; 

void nf_tables_destroy_set(const struct nft_ctx *ctx, struct nft_set *set)
{
	if (list_empty(&set->bindings) && nft_set_is_anonymous(set))
		nft_set_destroy(set);
}