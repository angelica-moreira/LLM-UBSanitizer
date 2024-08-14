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
struct regulator_dev {struct regulator* supply; int /*<<< orphan*/  is_switch; TYPE_1__* desc; } ;
struct regulator {struct regulator_dev* rdev; } ;
struct TYPE_2__ {int n_voltages; } ;

/* Variables and functions */
 int EINVAL ; 

int regulator_count_voltages(struct regulator *regulator)
{
	struct regulator_dev	*rdev = regulator->rdev;

	if (rdev->desc->n_voltages)
		return rdev->desc->n_voltages;

	if (!rdev->is_switch || !rdev->supply)
		return -EINVAL;

	return regulator_count_voltages(rdev->supply);
}