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
union power_supply_propval {int intval; } ;
typedef  int u8 ;
struct bq24190_dev_info {int f_reg; int /*<<< orphan*/  f_reg_lock; } ;

/* Variables and functions */
 int BQ24190_REG_F_BAT_FAULT_MASK ; 
 int BQ24190_REG_F_BOOST_FAULT_MASK ; 
 int BQ24190_REG_F_CHRG_FAULT_MASK ; 
 int BQ24190_REG_F_CHRG_FAULT_SHIFT ; 
 int BQ24190_REG_F_NTC_FAULT_MASK ; 
 int BQ24190_REG_F_NTC_FAULT_SHIFT ; 
 int POWER_SUPPLY_HEALTH_COLD ; 
 int POWER_SUPPLY_HEALTH_GOOD ; 
 int POWER_SUPPLY_HEALTH_OVERHEAT ; 
 int POWER_SUPPLY_HEALTH_OVERVOLTAGE ; 
 int POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE ; 
 int POWER_SUPPLY_HEALTH_UNKNOWN ; 
 int POWER_SUPPLY_HEALTH_UNSPEC_FAILURE ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int bq24190_charger_get_health(struct bq24190_dev_info *bdi,
		union power_supply_propval *val)
{
	u8 v;
	int health;

	mutex_lock(&bdi->f_reg_lock);
	v = bdi->f_reg;
	mutex_unlock(&bdi->f_reg_lock);

	if (v & BQ24190_REG_F_NTC_FAULT_MASK) {
		switch (v >> BQ24190_REG_F_NTC_FAULT_SHIFT & 0x7) {
		case 0x1: /* TS1  Cold */
		case 0x3: /* TS2  Cold */
		case 0x5: /* Both Cold */
			health = POWER_SUPPLY_HEALTH_COLD;
			break;
		case 0x2: /* TS1  Hot */
		case 0x4: /* TS2  Hot */
		case 0x6: /* Both Hot */
			health = POWER_SUPPLY_HEALTH_OVERHEAT;
			break;
		default:
			health = POWER_SUPPLY_HEALTH_UNKNOWN;
		}
	} else if (v & BQ24190_REG_F_BAT_FAULT_MASK) {
		health = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
	} else if (v & BQ24190_REG_F_CHRG_FAULT_MASK) {
		switch (v >> BQ24190_REG_F_CHRG_FAULT_SHIFT & 0x3) {
		case 0x1: /* Input Fault (VBUS OVP or VBAT<VBUS<3.8V) */
			/*
			 * This could be over-voltage or under-voltage
			 * and there's no way to tell which.  Instead
			 * of looking foolish and returning 'OVERVOLTAGE'
			 * when its really under-voltage, just return
			 * 'UNSPEC_FAILURE'.
			 */
			health = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
			break;
		case 0x2: /* Thermal Shutdown */
			health = POWER_SUPPLY_HEALTH_OVERHEAT;
			break;
		case 0x3: /* Charge Safety Timer Expiration */
			health = POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;
			break;
		default:  /* prevent compiler warning */
			health = -1;
		}
	} else if (v & BQ24190_REG_F_BOOST_FAULT_MASK) {
		/*
		 * This could be over-current or over-voltage but there's
		 * no way to tell which.  Return 'OVERVOLTAGE' since there
		 * isn't an 'OVERCURRENT' value defined that we can return
		 * even if it was over-current.
		 */
		health = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
	} else {
		health = POWER_SUPPLY_HEALTH_GOOD;
	}

	val->intval = health;

	return 0;
}