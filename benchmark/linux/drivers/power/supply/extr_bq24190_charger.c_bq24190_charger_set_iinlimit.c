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
union power_supply_propval {int /*<<< orphan*/  intval; } ;
struct bq24190_dev_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BQ24190_REG_ISC ; 
 int /*<<< orphan*/  BQ24190_REG_ISC_IINLIM_MASK ; 
 int /*<<< orphan*/  BQ24190_REG_ISC_IINLIM_SHIFT ; 
 int /*<<< orphan*/  bq24190_isc_iinlim_values ; 
 int bq24190_set_field_val (struct bq24190_dev_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int bq24190_charger_set_iinlimit(struct bq24190_dev_info *bdi,
		const union power_supply_propval *val)
{
	return bq24190_set_field_val(bdi, BQ24190_REG_ISC,
			BQ24190_REG_ISC_IINLIM_MASK,
			BQ24190_REG_ISC_IINLIM_SHIFT,
			bq24190_isc_iinlim_values,
			ARRAY_SIZE(bq24190_isc_iinlim_values), val->intval);
}