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
struct regmap {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 unsigned int CONTROL_MULT_SELECT ; 
 int DIV_ROUND_CLOSEST (unsigned long,int) ; 
 int EINVAL ; 
#define  LTC2945_ADIN_H 147 
 int /*<<< orphan*/  LTC2945_CONTROL ; 
#define  LTC2945_MAX_ADIN_H 146 
#define  LTC2945_MAX_ADIN_THRES_H 145 
#define  LTC2945_MAX_POWER_H 144 
#define  LTC2945_MAX_POWER_THRES_H 143 
#define  LTC2945_MAX_SENSE_H 142 
#define  LTC2945_MAX_SENSE_THRES_H 141 
#define  LTC2945_MAX_VIN_H 140 
#define  LTC2945_MAX_VIN_THRES_H 139 
#define  LTC2945_MIN_ADIN_H 138 
#define  LTC2945_MIN_ADIN_THRES_H 137 
#define  LTC2945_MIN_POWER_H 136 
#define  LTC2945_MIN_POWER_THRES_H 135 
#define  LTC2945_MIN_SENSE_H 134 
#define  LTC2945_MIN_SENSE_THRES_H 133 
#define  LTC2945_MIN_VIN_H 132 
#define  LTC2945_MIN_VIN_THRES_H 131 
#define  LTC2945_POWER_H 130 
#define  LTC2945_SENSE_H 129 
#define  LTC2945_VIN_H 128 
 struct regmap* dev_get_drvdata (struct device*) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 

__attribute__((used)) static int ltc2945_val_to_reg(struct device *dev, u8 reg,
			      unsigned long val)
{
	struct regmap *regmap = dev_get_drvdata(dev);
	unsigned int control;
	int ret;

	switch (reg) {
	case LTC2945_POWER_H:
	case LTC2945_MAX_POWER_H:
	case LTC2945_MIN_POWER_H:
	case LTC2945_MAX_POWER_THRES_H:
	case LTC2945_MIN_POWER_THRES_H:
		/*
		 * Convert to register value by assuming current is measured
		 * with an 1mOhm sense resistor, similar to current
		 * measurements.
		 * Control register bit 0 selects if voltage at SENSE+/VDD
		 * or voltage at ADIN is used to measure power, which in turn
		 * determines register calculations.
		 */
		ret = regmap_read(regmap, LTC2945_CONTROL, &control);
		if (ret < 0)
			return ret;
		if (control & CONTROL_MULT_SELECT) {
			/* 25 mV * 25 uV = 0.625 uV resolution. */
			val = DIV_ROUND_CLOSEST(val, 625);
		} else {
			/*
			 * 0.5 mV * 25 uV = 0.0125 uV resolution.
			 * Divide first to avoid overflow;
			 * accept loss of accuracy.
			 */
			val = DIV_ROUND_CLOSEST(val, 25) * 2;
		}
		break;
	case LTC2945_VIN_H:
	case LTC2945_MAX_VIN_H:
	case LTC2945_MIN_VIN_H:
	case LTC2945_MAX_VIN_THRES_H:
	case LTC2945_MIN_VIN_THRES_H:
		/* 25 mV resolution. */
		val /= 25;
		break;
	case LTC2945_ADIN_H:
	case LTC2945_MAX_ADIN_H:
	case LTC2945_MIN_ADIN_THRES_H:
	case LTC2945_MAX_ADIN_THRES_H:
	case LTC2945_MIN_ADIN_H:
		/* 0.5mV resolution. */
		val *= 2;
		break;
	case LTC2945_SENSE_H:
	case LTC2945_MAX_SENSE_H:
	case LTC2945_MIN_SENSE_H:
	case LTC2945_MAX_SENSE_THRES_H:
	case LTC2945_MIN_SENSE_THRES_H:
		/*
		 * 25 uV resolution. Convert to current as measured with
		 * an 1 mOhm sense resistor, in mA. If a different sense
		 * resistor is installed, calculate the actual current by
		 * dividing the reported current by the sense resistor value
		 * in mOhm.
		 */
		val = DIV_ROUND_CLOSEST(val, 25);
		break;
	default:
		return -EINVAL;
	}
	return val;
}