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
struct regulator_dev {int dummy; } ;
struct ab3100_regulator {TYPE_1__* plfdata; } ;
struct TYPE_2__ {int external_voltage; } ;

/* Variables and functions */
 struct ab3100_regulator* rdev_get_drvdata (struct regulator_dev*) ; 

__attribute__((used)) static int ab3100_get_voltage_regulator_external(struct regulator_dev *reg)
{
	struct ab3100_regulator *abreg = rdev_get_drvdata(reg);

	if (abreg->plfdata)
		return abreg->plfdata->external_voltage;
	else
		/* TODO: encode external voltage into device tree */
		return 0;
}