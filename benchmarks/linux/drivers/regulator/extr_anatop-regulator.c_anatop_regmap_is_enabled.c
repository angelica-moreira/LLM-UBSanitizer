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
struct regulator_dev {int dummy; } ;

/* Variables and functions */
 scalar_t__ LDO_POWER_GATE ; 
 scalar_t__ regulator_get_voltage_sel_regmap (struct regulator_dev*) ; 

__attribute__((used)) static int anatop_regmap_is_enabled(struct regulator_dev *reg)
{
	return regulator_get_voltage_sel_regmap(reg) != LDO_POWER_GATE;
}