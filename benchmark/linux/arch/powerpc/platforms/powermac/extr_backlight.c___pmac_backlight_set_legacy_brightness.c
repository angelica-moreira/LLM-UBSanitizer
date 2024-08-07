#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct backlight_properties {int brightness; int max_brightness; } ;
struct TYPE_3__ {struct backlight_properties props; } ;

/* Variables and functions */
 int ENXIO ; 
 int OLD_BACKLIGHT_MAX ; 
 int /*<<< orphan*/  backlight_update_status (TYPE_1__*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_1__* pmac_backlight ; 
 int /*<<< orphan*/  pmac_backlight_mutex ; 

__attribute__((used)) static int __pmac_backlight_set_legacy_brightness(int brightness)
{
	int error = -ENXIO;

	mutex_lock(&pmac_backlight_mutex);
	if (pmac_backlight) {
		struct backlight_properties *props;

		props = &pmac_backlight->props;
		props->brightness = brightness *
			(props->max_brightness + 1) /
			(OLD_BACKLIGHT_MAX + 1);

		if (props->brightness > props->max_brightness)
			props->brightness = props->max_brightness;
		else if (props->brightness < 0)
			props->brightness = 0;

		backlight_update_status(pmac_backlight);

		error = 0;
	}
	mutex_unlock(&pmac_backlight_mutex);

	return error;
}