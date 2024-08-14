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
struct vc_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VC_CAPSLOCK ; 
 int /*<<< orphan*/  chg_vc_kbd_led (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kbd ; 
 scalar_t__ rep ; 

__attribute__((used)) static void fn_caps_toggle(struct vc_data *vc)
{
	if (rep)
		return;

	chg_vc_kbd_led(kbd, VC_CAPSLOCK);
}