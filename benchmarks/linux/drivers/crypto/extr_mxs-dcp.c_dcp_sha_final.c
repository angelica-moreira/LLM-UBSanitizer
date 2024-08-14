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
struct ahash_request {scalar_t__ nbytes; int /*<<< orphan*/  result; } ;

/* Variables and functions */
 int /*<<< orphan*/  ahash_request_set_crypt (struct ahash_request*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dcp_sha_update_fx (struct ahash_request*,int) ; 

__attribute__((used)) static int dcp_sha_final(struct ahash_request *req)
{
	ahash_request_set_crypt(req, NULL, req->result, 0);
	req->nbytes = 0;
	return dcp_sha_update_fx(req, 1);
}