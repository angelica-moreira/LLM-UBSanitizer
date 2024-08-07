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
struct TYPE_4__ {TYPE_1__* rfbdev; } ;
struct radeon_device {TYPE_2__ mode_info; } ;
struct TYPE_3__ {int /*<<< orphan*/  helper; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_fb_helper_set_suspend (int /*<<< orphan*/ *,int) ; 

void radeon_fbdev_set_suspend(struct radeon_device *rdev, int state)
{
	if (rdev->mode_info.rfbdev)
		drm_fb_helper_set_suspend(&rdev->mode_info.rfbdev->helper, state);
}