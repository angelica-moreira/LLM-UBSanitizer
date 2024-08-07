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
struct backlight_device {int /*<<< orphan*/  dev; } ;
struct acx565akm_panel {int /*<<< orphan*/  mutex; } ;

/* Variables and functions */
 int acx565akm_bl_update_status_locked (struct backlight_device*) ; 
 struct acx565akm_panel* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int acx565akm_bl_update_status(struct backlight_device *dev)
{
	struct acx565akm_panel *lcd = dev_get_drvdata(&dev->dev);
	int ret;

	mutex_lock(&lcd->mutex);
	ret = acx565akm_bl_update_status_locked(dev);
	mutex_unlock(&lcd->mutex);

	return ret;
}