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
struct acpi_battery {int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int POWER_SUPPLY_TECHNOLOGY_LION ; 
 int POWER_SUPPLY_TECHNOLOGY_LIPO ; 
 int POWER_SUPPLY_TECHNOLOGY_NiCd ; 
 int POWER_SUPPLY_TECHNOLOGY_NiMH ; 
 int POWER_SUPPLY_TECHNOLOGY_UNKNOWN ; 
 int /*<<< orphan*/  strcasecmp (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strncasecmp (char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int acpi_battery_technology(struct acpi_battery *battery)
{
	if (!strcasecmp("NiCd", battery->type))
		return POWER_SUPPLY_TECHNOLOGY_NiCd;
	if (!strcasecmp("NiMH", battery->type))
		return POWER_SUPPLY_TECHNOLOGY_NiMH;
	if (!strcasecmp("LION", battery->type))
		return POWER_SUPPLY_TECHNOLOGY_LION;
	if (!strncasecmp("LI-ION", battery->type, 6))
		return POWER_SUPPLY_TECHNOLOGY_LION;
	if (!strcasecmp("LiP", battery->type))
		return POWER_SUPPLY_TECHNOLOGY_LIPO;
	return POWER_SUPPLY_TECHNOLOGY_UNKNOWN;
}