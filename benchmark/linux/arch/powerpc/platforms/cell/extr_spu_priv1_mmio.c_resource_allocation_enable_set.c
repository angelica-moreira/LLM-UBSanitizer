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
typedef  int /*<<< orphan*/  u64 ;
struct spu {TYPE_1__* priv1; } ;
struct TYPE_2__ {int /*<<< orphan*/  resource_allocation_enable_RW; } ;

/* Variables and functions */
 int /*<<< orphan*/  out_be64 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void resource_allocation_enable_set(struct spu *spu, u64 enable)
{
	out_be64(&spu->priv1->resource_allocation_enable_RW, enable);
}