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
struct arizona_micsupp {int /*<<< orphan*/  check_cp_work; } ;

/* Variables and functions */
 struct arizona_micsupp* rdev_get_drvdata (struct regulator_dev*) ; 
 int regulator_set_bypass_regmap (struct regulator_dev*,int) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int arizona_micsupp_set_bypass(struct regulator_dev *rdev, bool ena)
{
	struct arizona_micsupp *micsupp = rdev_get_drvdata(rdev);
	int ret;

	ret = regulator_set_bypass_regmap(rdev, ena);
	if (ret == 0)
		schedule_work(&micsupp->check_cp_work);

	return ret;
}