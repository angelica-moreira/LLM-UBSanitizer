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
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct gbphy_device {int dummy; } ;
struct gb_pwm_config_request {void* period; void* duty; scalar_t__ which; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;
struct gb_pwm_chip {scalar_t__ pwm_max; int /*<<< orphan*/  connection; TYPE_1__ chip; } ;
typedef  int /*<<< orphan*/  request ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  GB_PWM_TYPE_CONFIG ; 
 void* cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int gb_operation_sync (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct gb_pwm_config_request*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int gbphy_runtime_get_sync (struct gbphy_device*) ; 
 int /*<<< orphan*/  gbphy_runtime_put_autosuspend (struct gbphy_device*) ; 
 struct gbphy_device* to_gbphy_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int gb_pwm_config_operation(struct gb_pwm_chip *pwmc,
				   u8 which, u32 duty, u32 period)
{
	struct gb_pwm_config_request request;
	struct gbphy_device *gbphy_dev;
	int ret;

	if (which > pwmc->pwm_max)
		return -EINVAL;

	request.which = which;
	request.duty = cpu_to_le32(duty);
	request.period = cpu_to_le32(period);

	gbphy_dev = to_gbphy_dev(pwmc->chip.dev);
	ret = gbphy_runtime_get_sync(gbphy_dev);
	if (ret)
		return ret;

	ret = gb_operation_sync(pwmc->connection, GB_PWM_TYPE_CONFIG,
				&request, sizeof(request), NULL, 0);

	gbphy_runtime_put_autosuspend(gbphy_dev);

	return ret;
}