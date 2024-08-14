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
struct scrub_ctx {int /*<<< orphan*/  list_wait; int /*<<< orphan*/  bios_in_flight; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  scrub_put_ctx (struct scrub_ctx*) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void scrub_pending_bio_dec(struct scrub_ctx *sctx)
{
	atomic_dec(&sctx->bios_in_flight);
	wake_up(&sctx->list_wait);
	scrub_put_ctx(sctx);
}