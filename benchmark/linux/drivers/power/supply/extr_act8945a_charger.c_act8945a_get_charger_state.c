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
 int /*<<< orphan*/  ACT8945A_APCH_STATE ; 
 int /*<<< orphan*/  ACT8945A_APCH_STATUS ; 
 unsigned int APCH_STATE_CSTATE ; 
#define  APCH_STATE_CSTATE_DISABLED 131 
#define  APCH_STATE_CSTATE_EOC 130 
#define  APCH_STATE_CSTATE_FAST 129 
#define  APCH_STATE_CSTATE_PRE 128 
 unsigned int APCH_STATE_CSTATE_SHIFT ; 
 unsigned int APCH_STATUS_CHGDAT ; 
 unsigned int APCH_STATUS_INDAT ; 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_DISCHARGING ; 
 int POWER_SUPPLY_STATUS_FULL ; 
 int POWER_SUPPLY_STATUS_NOT_CHARGING ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 

__attribute__((used)) static int act8945a_get_charger_state(struct regmap *regmap, int *val)
{
	int ret;
	unsigned int status, state;

	ret = regmap_read(regmap, ACT8945A_APCH_STATUS, &status);
	if (ret < 0)
		return ret;

	ret = regmap_read(regmap, ACT8945A_APCH_STATE, &state);
	if (ret < 0)
		return ret;

	state &= APCH_STATE_CSTATE;
	state >>= APCH_STATE_CSTATE_SHIFT;

	switch (state) {
	case APCH_STATE_CSTATE_PRE:
	case APCH_STATE_CSTATE_FAST:
		*val = POWER_SUPPLY_STATUS_CHARGING;
		break;
	case APCH_STATE_CSTATE_EOC:
		if (status & APCH_STATUS_CHGDAT)
			*val = POWER_SUPPLY_STATUS_FULL;
		else
			*val = POWER_SUPPLY_STATUS_CHARGING;
		break;
	case APCH_STATE_CSTATE_DISABLED:
	default:
		if (!(status & APCH_STATUS_INDAT))
			*val = POWER_SUPPLY_STATUS_DISCHARGING;
		else
			*val = POWER_SUPPLY_STATUS_NOT_CHARGING;
		break;
	}

	return 0;
}