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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PPSMC_MSG_NoForcedLevel ; 
 int trinity_notify_message_to_smu (struct radeon_device*,int /*<<< orphan*/ ) ; 

int trinity_dpm_no_forced_level(struct radeon_device *rdev)
{
	return trinity_notify_message_to_smu(rdev, PPSMC_MSG_NoForcedLevel);
}