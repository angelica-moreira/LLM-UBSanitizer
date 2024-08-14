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
struct ci_power_info {int active_auto_throttle_sources; } ;
typedef  enum radeon_dpm_auto_throttle_src { ____Placeholder_radeon_dpm_auto_throttle_src } radeon_dpm_auto_throttle_src ;

/* Variables and functions */
 struct ci_power_info* ci_get_pi (struct radeon_device*) ; 
 int /*<<< orphan*/  ci_set_dpm_event_sources (struct radeon_device*,int) ; 

__attribute__((used)) static void ci_enable_auto_throttle_source(struct radeon_device *rdev,
					   enum radeon_dpm_auto_throttle_src source,
					   bool enable)
{
	struct ci_power_info *pi = ci_get_pi(rdev);

	if (enable) {
		if (!(pi->active_auto_throttle_sources & (1 << source))) {
			pi->active_auto_throttle_sources |= 1 << source;
			ci_set_dpm_event_sources(rdev, pi->active_auto_throttle_sources);
		}
	} else {
		if (pi->active_auto_throttle_sources & (1 << source)) {
			pi->active_auto_throttle_sources &= ~(1 << source);
			ci_set_dpm_event_sources(rdev, pi->active_auto_throttle_sources);
		}
	}
}