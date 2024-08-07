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
struct ahash_request {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ahash_request_ctx (struct ahash_request*) ; 
 int crypto_shash_export (int /*<<< orphan*/ ,void*) ; 

__attribute__((used)) static int shash_async_export(struct ahash_request *req, void *out)
{
	return crypto_shash_export(ahash_request_ctx(req), out);
}