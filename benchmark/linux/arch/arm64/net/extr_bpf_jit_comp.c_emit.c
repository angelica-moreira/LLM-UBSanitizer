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
typedef  int /*<<< orphan*/  u32 ;
struct jit_ctx {size_t idx; int /*<<< orphan*/ * image; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/  const) ; 

__attribute__((used)) static inline void emit(const u32 insn, struct jit_ctx *ctx)
{
	if (ctx->image != NULL)
		ctx->image[ctx->idx] = cpu_to_le32(insn);

	ctx->idx++;
}