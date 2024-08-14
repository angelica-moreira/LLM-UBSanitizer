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
struct qla_hw_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PCIE_SEM2_UNLOCK ; 
 int /*<<< orphan*/  QLA82XX_PCIE_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QLA82XX_ROM_LOCK_ID ; 
 int /*<<< orphan*/  qla82xx_rd_32 (struct qla_hw_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qla82xx_wr_32 (struct qla_hw_data*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
qla82xx_rom_unlock(struct qla_hw_data *ha)
{
	qla82xx_wr_32(ha, QLA82XX_ROM_LOCK_ID, 0xffffffff);
	qla82xx_rd_32(ha, QLA82XX_PCIE_REG(PCIE_SEM2_UNLOCK));
}