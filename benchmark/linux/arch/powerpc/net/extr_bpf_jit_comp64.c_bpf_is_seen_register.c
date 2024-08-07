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
struct codegen_context {int seen; } ;

/* Variables and functions */
 int* b2p ; 

__attribute__((used)) static inline bool bpf_is_seen_register(struct codegen_context *ctx, int i)
{
	return (ctx->seen & (1 << (31 - b2p[i])));
}