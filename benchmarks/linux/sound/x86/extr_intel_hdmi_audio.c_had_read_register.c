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
typedef  scalar_t__ u32 ;
struct snd_intelhad {int /*<<< orphan*/  pipe; int /*<<< orphan*/  card_ctx; int /*<<< orphan*/  connected; } ;

/* Variables and functions */
 scalar_t__ had_read_register_raw (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void had_read_register(struct snd_intelhad *ctx, u32 reg, u32 *val)
{
	if (!ctx->connected)
		*val = 0;
	else
		*val = had_read_register_raw(ctx->card_ctx, ctx->pipe, reg);
}