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
struct hinic_hwif {scalar_t__ cfg_regs_bar; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_be32 (scalar_t__) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void hinic_hwif_write_reg(struct hinic_hwif *hwif, u32 reg,
					u32 val)
{
	writel(cpu_to_be32(val), hwif->cfg_regs_bar + reg);
}