#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  workspace; } ;
struct deflate_ctx {TYPE_1__ comp_stream; } ;

/* Variables and functions */
 int /*<<< orphan*/  vfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zlib_deflateEnd (TYPE_1__*) ; 

__attribute__((used)) static void deflate_comp_exit(struct deflate_ctx *ctx)
{
	zlib_deflateEnd(&ctx->comp_stream);
	vfree(ctx->comp_stream.workspace);
}