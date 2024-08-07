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
typedef  scalar_t__ u_int ;
struct pxafb_info {scalar_t__ state; int /*<<< orphan*/  ctrlr_lock; } ;

/* Variables and functions */
#define  C_DISABLE 134 
#define  C_DISABLE_CLKCHANGE 133 
#define  C_DISABLE_PM 132 
#define  C_ENABLE 131 
#define  C_ENABLE_CLKCHANGE 130 
#define  C_ENABLE_PM 129 
#define  C_REENABLE 128 
 scalar_t__ C_STARTUP ; 
 int /*<<< orphan*/  __pxafb_backlight_power (struct pxafb_info*,int) ; 
 int /*<<< orphan*/  __pxafb_lcd_power (struct pxafb_info*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pxafb_disable_controller (struct pxafb_info*) ; 
 int /*<<< orphan*/  pxafb_enable_controller (struct pxafb_info*) ; 

__attribute__((used)) static void set_ctrlr_state(struct pxafb_info *fbi, u_int state)
{
	u_int old_state;

	mutex_lock(&fbi->ctrlr_lock);

	old_state = fbi->state;

	/*
	 * Hack around fbcon initialisation.
	 */
	if (old_state == C_STARTUP && state == C_REENABLE)
		state = C_ENABLE;

	switch (state) {
	case C_DISABLE_CLKCHANGE:
		/*
		 * Disable controller for clock change.  If the
		 * controller is already disabled, then do nothing.
		 */
		if (old_state != C_DISABLE && old_state != C_DISABLE_PM) {
			fbi->state = state;
			/* TODO __pxafb_lcd_power(fbi, 0); */
			pxafb_disable_controller(fbi);
		}
		break;

	case C_DISABLE_PM:
	case C_DISABLE:
		/*
		 * Disable controller
		 */
		if (old_state != C_DISABLE) {
			fbi->state = state;
			__pxafb_backlight_power(fbi, 0);
			__pxafb_lcd_power(fbi, 0);
			if (old_state != C_DISABLE_CLKCHANGE)
				pxafb_disable_controller(fbi);
		}
		break;

	case C_ENABLE_CLKCHANGE:
		/*
		 * Enable the controller after clock change.  Only
		 * do this if we were disabled for the clock change.
		 */
		if (old_state == C_DISABLE_CLKCHANGE) {
			fbi->state = C_ENABLE;
			pxafb_enable_controller(fbi);
			/* TODO __pxafb_lcd_power(fbi, 1); */
		}
		break;

	case C_REENABLE:
		/*
		 * Re-enable the controller only if it was already
		 * enabled.  This is so we reprogram the control
		 * registers.
		 */
		if (old_state == C_ENABLE) {
			__pxafb_lcd_power(fbi, 0);
			pxafb_disable_controller(fbi);
			pxafb_enable_controller(fbi);
			__pxafb_lcd_power(fbi, 1);
		}
		break;

	case C_ENABLE_PM:
		/*
		 * Re-enable the controller after PM.  This is not
		 * perfect - think about the case where we were doing
		 * a clock change, and we suspended half-way through.
		 */
		if (old_state != C_DISABLE_PM)
			break;
		/* fall through */

	case C_ENABLE:
		/*
		 * Power up the LCD screen, enable controller, and
		 * turn on the backlight.
		 */
		if (old_state != C_ENABLE) {
			fbi->state = C_ENABLE;
			pxafb_enable_controller(fbi);
			__pxafb_lcd_power(fbi, 1);
			__pxafb_backlight_power(fbi, 1);
		}
		break;
	}
	mutex_unlock(&fbi->ctrlr_lock);
}