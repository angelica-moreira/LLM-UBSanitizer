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
struct request_member {scalar_t__ mask; } ;
struct rpm_reg_parts {struct request_member enable_state; } ;
struct regulator_dev {int dummy; } ;
struct qcom_rpm_reg {int is_enabled; int /*<<< orphan*/  lock; struct rpm_reg_parts* parts; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct qcom_rpm_reg* rdev_get_drvdata (struct regulator_dev*) ; 
 int rpm_reg_write (struct qcom_rpm_reg*,struct request_member const*,int) ; 

__attribute__((used)) static int rpm_reg_switch_enable(struct regulator_dev *rdev)
{
	struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
	const struct rpm_reg_parts *parts = vreg->parts;
	const struct request_member *req = &parts->enable_state;
	int ret;

	if (req->mask == 0)
		return -EINVAL;

	mutex_lock(&vreg->lock);
	ret = rpm_reg_write(vreg, req, 1);
	if (!ret)
		vreg->is_enabled = 1;
	mutex_unlock(&vreg->lock);

	return ret;
}