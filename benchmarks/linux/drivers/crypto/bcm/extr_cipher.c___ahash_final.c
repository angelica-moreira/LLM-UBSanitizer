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
struct iproc_reqctx_s {int is_final; } ;
struct ahash_request {int /*<<< orphan*/  nbytes; } ;

/* Variables and functions */
 int ahash_enqueue (struct ahash_request*) ; 
 struct iproc_reqctx_s* ahash_request_ctx (struct ahash_request*) ; 
 int /*<<< orphan*/  flow_log (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int __ahash_final(struct ahash_request *req)
{
	struct iproc_reqctx_s *rctx = ahash_request_ctx(req);

	flow_log("ahash_final() nbytes:%u\n", req->nbytes);

	rctx->is_final = 1;

	return ahash_enqueue(req);
}