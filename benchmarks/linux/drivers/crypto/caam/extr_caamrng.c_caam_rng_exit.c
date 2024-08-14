#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  jrdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  caam_jr_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  caam_rng ; 
 int /*<<< orphan*/  hwrng_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  init_done ; 
 int /*<<< orphan*/  kfree (TYPE_1__*) ; 
 TYPE_1__* rng_ctx ; 

void caam_rng_exit(void)
{
	if (!init_done)
		return;

	caam_jr_free(rng_ctx->jrdev);
	hwrng_unregister(&caam_rng);
	kfree(rng_ctx);
}