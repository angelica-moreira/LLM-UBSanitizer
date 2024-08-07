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
struct rv_jit_context {int* offset; } ;

/* Variables and functions */

__attribute__((used)) static int rv_offset(int bpf_to, int bpf_from, struct rv_jit_context *ctx)
{
	int from = ctx->offset[bpf_from] - 1, to = ctx->offset[bpf_to];

	return (to - from) << 2;
}