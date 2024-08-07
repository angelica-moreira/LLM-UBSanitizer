#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct ov5640_dev {TYPE_2__* supplies; TYPE_1__* i2c_client; } ;
struct TYPE_4__ {int /*<<< orphan*/  supply; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int OV5640_NUM_SUPPLIES ; 
 int devm_regulator_bulk_get (int /*<<< orphan*/ *,int,TYPE_2__*) ; 
 int /*<<< orphan*/ * ov5640_supply_name ; 

__attribute__((used)) static int ov5640_get_regulators(struct ov5640_dev *sensor)
{
	int i;

	for (i = 0; i < OV5640_NUM_SUPPLIES; i++)
		sensor->supplies[i].supply = ov5640_supply_name[i];

	return devm_regulator_bulk_get(&sensor->i2c_client->dev,
				       OV5640_NUM_SUPPLIES,
				       sensor->supplies);
}