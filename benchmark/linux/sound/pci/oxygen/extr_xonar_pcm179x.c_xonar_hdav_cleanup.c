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
struct oxygen {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  xonar_disable_output (struct oxygen*) ; 
 int /*<<< orphan*/  xonar_hdmi_cleanup (struct oxygen*) ; 

__attribute__((used)) static void xonar_hdav_cleanup(struct oxygen *chip)
{
	xonar_hdmi_cleanup(chip);
	xonar_disable_output(chip);
	msleep(2);
}