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
struct brcms_c_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  brcms_c_watchdog (struct brcms_c_info*) ; 

__attribute__((used)) static void brcms_c_watchdog_by_timer(void *arg)
{
	struct brcms_c_info *wlc = (struct brcms_c_info *) arg;

	brcms_c_watchdog(wlc);
}