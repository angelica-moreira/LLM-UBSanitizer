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
typedef  int /*<<< orphan*/  u8 ;
struct jit_ctx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARM_BLX_R (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ARM_LR ; 
 int /*<<< orphan*/  ARM_MOV_R (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ARM_PC ; 
 int /*<<< orphan*/  emit (int /*<<< orphan*/ ,struct jit_ctx*) ; 
 int /*<<< orphan*/  emit_bx_r (int /*<<< orphan*/ ,struct jit_ctx*) ; 

__attribute__((used)) static inline void emit_blx_r(u8 tgt_reg, struct jit_ctx *ctx)
{
#if __LINUX_ARM_ARCH__ < 5
	emit(ARM_MOV_R(ARM_LR, ARM_PC), ctx);
	emit_bx_r(tgt_reg, ctx);
#else
	emit(ARM_BLX_R(tgt_reg), ctx);
#endif
}