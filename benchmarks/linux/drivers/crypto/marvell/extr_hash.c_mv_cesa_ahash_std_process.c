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
typedef  int /*<<< orphan*/  u32 ;
struct mv_cesa_ahash_std_req {scalar_t__ offset; } ;
struct TYPE_2__ {struct mv_cesa_ahash_std_req std; } ;
struct mv_cesa_ahash_req {scalar_t__ cache_ptr; TYPE_1__ req; } ;
struct ahash_request {scalar_t__ nbytes; } ;

/* Variables and functions */
 int EINPROGRESS ; 
 struct mv_cesa_ahash_req* ahash_request_ctx (struct ahash_request*) ; 

__attribute__((used)) static int mv_cesa_ahash_std_process(struct ahash_request *req, u32 status)
{
	struct mv_cesa_ahash_req *creq = ahash_request_ctx(req);
	struct mv_cesa_ahash_std_req *sreq = &creq->req.std;

	if (sreq->offset < (req->nbytes - creq->cache_ptr))
		return -EINPROGRESS;

	return 0;
}