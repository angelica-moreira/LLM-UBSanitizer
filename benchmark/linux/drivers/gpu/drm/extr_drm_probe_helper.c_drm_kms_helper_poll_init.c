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
struct TYPE_2__ {int poll_enabled; int /*<<< orphan*/  output_poll_work; } ;
struct drm_device {TYPE_1__ mode_config; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_DELAYED_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_kms_helper_poll_enable (struct drm_device*) ; 
 int /*<<< orphan*/  output_poll_execute ; 

void drm_kms_helper_poll_init(struct drm_device *dev)
{
	INIT_DELAYED_WORK(&dev->mode_config.output_poll_work, output_poll_execute);
	dev->mode_config.poll_enabled = true;

	drm_kms_helper_poll_enable(dev);
}