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
struct crypto_async_request {int /*<<< orphan*/  (* complete ) (struct crypto_async_request*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct crypto_async_request*,int) ; 

__attribute__((used)) static void rk_ahash_crypto_complete(struct crypto_async_request *base, int err)
{
	if (base->complete)
		base->complete(base, err);
}