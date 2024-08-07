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
typedef  int uint32_t ;
struct irq_source_info {int enable_reg; int enable_mask; int* enable_value; } ;
struct irq_service {int /*<<< orphan*/  ctx; } ;

/* Variables and functions */
 int dm_read_reg (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dm_write_reg (int /*<<< orphan*/ ,int,int) ; 

void dal_irq_service_set_generic(
	struct irq_service *irq_service,
	const struct irq_source_info *info,
	bool enable)
{
	uint32_t addr = info->enable_reg;
	uint32_t value = dm_read_reg(irq_service->ctx, addr);

	value = (value & ~info->enable_mask) |
		(info->enable_value[enable ? 0 : 1] & info->enable_mask);
	dm_write_reg(irq_service->ctx, addr, value);
}