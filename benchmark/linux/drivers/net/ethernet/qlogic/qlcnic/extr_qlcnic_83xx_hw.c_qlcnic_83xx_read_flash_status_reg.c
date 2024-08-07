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
typedef  int u32 ;
struct qlcnic_adapter {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int QLCRD32 (struct qlcnic_adapter*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  QLC_83XX_FLASH_ADDR ; 
 int /*<<< orphan*/  QLC_83XX_FLASH_CONTROL ; 
 int /*<<< orphan*/  QLC_83XX_FLASH_OEM_READ_SIG ; 
 int /*<<< orphan*/  QLC_83XX_FLASH_RDDATA ; 
 int /*<<< orphan*/  QLC_83XX_FLASH_READ_CTRL ; 
 int qlcnic_83xx_poll_flash_status_reg (struct qlcnic_adapter*) ; 
 int /*<<< orphan*/  qlcnic_83xx_wrt_reg_indirect (struct qlcnic_adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int qlcnic_83xx_read_flash_status_reg(struct qlcnic_adapter *adapter)
{
	int ret, err = 0;
	u32 temp;

	qlcnic_83xx_wrt_reg_indirect(adapter, QLC_83XX_FLASH_ADDR,
				     QLC_83XX_FLASH_OEM_READ_SIG);
	qlcnic_83xx_wrt_reg_indirect(adapter, QLC_83XX_FLASH_CONTROL,
				     QLC_83XX_FLASH_READ_CTRL);
	ret = qlcnic_83xx_poll_flash_status_reg(adapter);
	if (ret)
		return -EIO;

	temp = QLCRD32(adapter, QLC_83XX_FLASH_RDDATA, &err);
	if (err == -EIO)
		return err;

	return temp & 0xFF;
}