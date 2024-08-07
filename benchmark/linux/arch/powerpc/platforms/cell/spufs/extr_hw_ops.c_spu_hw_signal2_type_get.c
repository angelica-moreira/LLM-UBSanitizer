#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
struct spu_context {TYPE_2__* spu; } ;
struct TYPE_4__ {TYPE_1__* priv2; } ;
struct TYPE_3__ {int /*<<< orphan*/  spu_cfg_RW; } ;

/* Variables and functions */
 int in_be64 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static u64 spu_hw_signal2_type_get(struct spu_context *ctx)
{
	return ((in_be64(&ctx->spu->priv2->spu_cfg_RW) & 2) != 0);
}