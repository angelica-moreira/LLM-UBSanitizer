#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct power_supply {TYPE_1__* desc; } ;
struct TYPE_2__ {scalar_t__ type; } ;

/* Variables and functions */
 scalar_t__ POWER_SUPPLY_TYPE_BATTERY ; 
 int power_supply_create_bat_triggers (struct power_supply*) ; 
 int power_supply_create_gen_triggers (struct power_supply*) ; 

int power_supply_create_triggers(struct power_supply *psy)
{
	if (psy->desc->type == POWER_SUPPLY_TYPE_BATTERY)
		return power_supply_create_bat_triggers(psy);
	return power_supply_create_gen_triggers(psy);
}