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
typedef  int u8 ;
struct rockchip_pinctrl {struct regmap* regmap_base; struct regmap* regmap_pmu; } ;
struct rockchip_pin_bank {int bank_num; struct rockchip_pinctrl* drvdata; } ;
struct regmap {int dummy; } ;

/* Variables and functions */
 int RV1108_DRV_BANK_STRIDE ; 
 int RV1108_DRV_BITS_PER_PIN ; 
 int RV1108_DRV_GRF_OFFSET ; 
 int RV1108_DRV_PINS_PER_REG ; 
 int RV1108_DRV_PMU_OFFSET ; 

__attribute__((used)) static void rv1108_calc_drv_reg_and_bit(struct rockchip_pin_bank *bank,
					int pin_num, struct regmap **regmap,
					int *reg, u8 *bit)
{
	struct rockchip_pinctrl *info = bank->drvdata;

	/* The first 24 pins of the first bank are located in PMU */
	if (bank->bank_num == 0) {
		*regmap = info->regmap_pmu;
		*reg = RV1108_DRV_PMU_OFFSET;
	} else {
		*regmap = info->regmap_base;
		*reg = RV1108_DRV_GRF_OFFSET;

		/* correct the offset, as we're starting with the 2nd bank */
		*reg -= 0x10;
		*reg += bank->bank_num * RV1108_DRV_BANK_STRIDE;
	}

	*reg += ((pin_num / RV1108_DRV_PINS_PER_REG) * 4);
	*bit = pin_num % RV1108_DRV_PINS_PER_REG;
	*bit *= RV1108_DRV_BITS_PER_PIN;
}