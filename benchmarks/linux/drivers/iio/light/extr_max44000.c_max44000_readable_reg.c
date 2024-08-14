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
struct device {int dummy; } ;

/* Variables and functions */
#define  MAX44000_REG_ALS_DATA_HI 143 
#define  MAX44000_REG_ALS_DATA_LO 142 
#define  MAX44000_REG_ALS_LOTHR_HI 141 
#define  MAX44000_REG_ALS_LOTHR_LO 140 
#define  MAX44000_REG_ALS_UPTHR_HI 139 
#define  MAX44000_REG_ALS_UPTHR_LO 138 
#define  MAX44000_REG_CFG_MAIN 137 
#define  MAX44000_REG_CFG_RX 136 
#define  MAX44000_REG_CFG_TX 135 
#define  MAX44000_REG_PRX_DATA 134 
#define  MAX44000_REG_PRX_IND 133 
#define  MAX44000_REG_PRX_THR 132 
#define  MAX44000_REG_PST 131 
#define  MAX44000_REG_STATUS 130 
#define  MAX44000_REG_TRIM_GAIN_GREEN 129 
#define  MAX44000_REG_TRIM_GAIN_IR 128 

__attribute__((used)) static bool max44000_readable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX44000_REG_STATUS:
	case MAX44000_REG_CFG_MAIN:
	case MAX44000_REG_CFG_RX:
	case MAX44000_REG_CFG_TX:
	case MAX44000_REG_ALS_DATA_HI:
	case MAX44000_REG_ALS_DATA_LO:
	case MAX44000_REG_PRX_DATA:
	case MAX44000_REG_ALS_UPTHR_HI:
	case MAX44000_REG_ALS_UPTHR_LO:
	case MAX44000_REG_ALS_LOTHR_HI:
	case MAX44000_REG_ALS_LOTHR_LO:
	case MAX44000_REG_PST:
	case MAX44000_REG_PRX_IND:
	case MAX44000_REG_PRX_THR:
	case MAX44000_REG_TRIM_GAIN_GREEN:
	case MAX44000_REG_TRIM_GAIN_IR:
		return true;
	default:
		return false;
	}
}