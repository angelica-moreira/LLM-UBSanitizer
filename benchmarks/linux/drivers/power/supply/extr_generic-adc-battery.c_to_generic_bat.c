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
struct power_supply {int dummy; } ;
struct gab {int dummy; } ;

/* Variables and functions */
 struct gab* power_supply_get_drvdata (struct power_supply*) ; 

__attribute__((used)) static struct gab *to_generic_bat(struct power_supply *psy)
{
	return power_supply_get_drvdata(psy);
}