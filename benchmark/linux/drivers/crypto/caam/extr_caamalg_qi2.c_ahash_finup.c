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
struct caam_hash_state {int (* finup ) (struct ahash_request*) ;} ;
struct ahash_request {int dummy; } ;

/* Variables and functions */
 struct caam_hash_state* ahash_request_ctx (struct ahash_request*) ; 
 int stub1 (struct ahash_request*) ; 

__attribute__((used)) static int ahash_finup(struct ahash_request *req)
{
	struct caam_hash_state *state = ahash_request_ctx(req);

	return state->finup(req);
}