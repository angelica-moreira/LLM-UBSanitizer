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
struct ahash_request {int /*<<< orphan*/  result; } ;

/* Variables and functions */
 int /*<<< orphan*/  ahash_request_ctx (struct ahash_request*) ; 
 int crypto_shash_final (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int shash_async_final(struct ahash_request *req)
{
	return crypto_shash_final(ahash_request_ctx(req), req->result);
}