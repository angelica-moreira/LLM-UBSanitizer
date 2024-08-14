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
struct regmap {int dummy; } ;

/* Variables and functions */
 unsigned int CHG_DETAILS_01_CHG_MASK ; 
 unsigned int CHG_DETAILS_01_CHG_SHIFT ; 
#define  MAX77693_CHARGING_DONE 139 
#define  MAX77693_CHARGING_FAST_CONST_CURRENT 138 
#define  MAX77693_CHARGING_FAST_CONST_VOLTAGE 137 
#define  MAX77693_CHARGING_HIGH_TEMP 136 
#define  MAX77693_CHARGING_OFF 135 
#define  MAX77693_CHARGING_OVER_TEMP 134 
#define  MAX77693_CHARGING_PREQUALIFICATION 133 
#define  MAX77693_CHARGING_RESERVED 132 
#define  MAX77693_CHARGING_THERMISTOR_SUSPEND 131 
#define  MAX77693_CHARGING_TIMER_EXPIRED 130 
#define  MAX77693_CHARGING_TOP_OFF 129 
#define  MAX77693_CHARGING_WATCHDOG_EXPIRED 128 
 int /*<<< orphan*/  MAX77693_CHG_REG_CHG_DETAILS_01 ; 
 int POWER_SUPPLY_CHARGE_TYPE_FAST ; 
 int POWER_SUPPLY_CHARGE_TYPE_NONE ; 
 int POWER_SUPPLY_CHARGE_TYPE_TRICKLE ; 
 int POWER_SUPPLY_CHARGE_TYPE_UNKNOWN ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 

__attribute__((used)) static int max77693_get_charge_type(struct regmap *regmap, int *val)
{
	int ret;
	unsigned int data;

	ret = regmap_read(regmap, MAX77693_CHG_REG_CHG_DETAILS_01, &data);
	if (ret < 0)
		return ret;

	data &= CHG_DETAILS_01_CHG_MASK;
	data >>= CHG_DETAILS_01_CHG_SHIFT;

	switch (data) {
	case MAX77693_CHARGING_PREQUALIFICATION:
	/*
	 * Top-off: trickle or fast? In top-off the current varies between
	 * 100 and 250 mA. It is higher than prequalification current.
	 */
	case MAX77693_CHARGING_TOP_OFF:
		*val = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
		break;
	case MAX77693_CHARGING_FAST_CONST_CURRENT:
	case MAX77693_CHARGING_FAST_CONST_VOLTAGE:
	/* In high temp the charging current is reduced, but still charging */
	case MAX77693_CHARGING_HIGH_TEMP:
		*val = POWER_SUPPLY_CHARGE_TYPE_FAST;
		break;
	case MAX77693_CHARGING_DONE:
	case MAX77693_CHARGING_TIMER_EXPIRED:
	case MAX77693_CHARGING_THERMISTOR_SUSPEND:
	case MAX77693_CHARGING_OFF:
	case MAX77693_CHARGING_OVER_TEMP:
	case MAX77693_CHARGING_WATCHDOG_EXPIRED:
		*val = POWER_SUPPLY_CHARGE_TYPE_NONE;
		break;
	case MAX77693_CHARGING_RESERVED:
	default:
		*val = POWER_SUPPLY_CHARGE_TYPE_UNKNOWN;
	}

	return 0;
}