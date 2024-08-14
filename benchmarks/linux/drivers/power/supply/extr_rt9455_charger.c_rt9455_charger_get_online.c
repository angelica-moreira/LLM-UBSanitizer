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
union power_supply_propval {int intval; } ;
struct rt9455_info {TYPE_1__* client; int /*<<< orphan*/ * regmap_fields; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 size_t F_PWR_RDY ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int regmap_field_read (int /*<<< orphan*/ ,unsigned int*) ; 

__attribute__((used)) static int rt9455_charger_get_online(struct rt9455_info *info,
				     union power_supply_propval *val)
{
	unsigned int v;
	int ret;

	ret = regmap_field_read(info->regmap_fields[F_PWR_RDY], &v);
	if (ret) {
		dev_err(&info->client->dev, "Failed to read PWR_RDY bit\n");
		return ret;
	}

	val->intval = (int)v;

	return 0;
}