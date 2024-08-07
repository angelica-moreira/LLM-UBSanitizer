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
struct work_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_KEY ; 
 int /*<<< orphan*/  applesmc_write_key (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  backlight_state ; 

__attribute__((used)) static void applesmc_backlight_set(struct work_struct *work)
{
	applesmc_write_key(BACKLIGHT_KEY, backlight_state, 2);
}