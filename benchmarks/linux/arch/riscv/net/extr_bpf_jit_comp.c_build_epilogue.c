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
struct rv_jit_context {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RV_REG_RA ; 
 int /*<<< orphan*/  __build_epilogue (int /*<<< orphan*/ ,struct rv_jit_context*) ; 

__attribute__((used)) static void build_epilogue(struct rv_jit_context *ctx)
{
	__build_epilogue(RV_REG_RA, ctx);
}