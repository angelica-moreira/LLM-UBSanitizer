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
typedef  int /*<<< orphan*/  uint16_t ;
typedef  int time64_t ;
struct rtc_wkalrm {scalar_t__ enabled; int /*<<< orphan*/  time; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ECMPHREG ; 
 int /*<<< orphan*/  ECMPLREG ; 
 int /*<<< orphan*/  ECMPMREG ; 
 int /*<<< orphan*/  aie_irq ; 
 scalar_t__ alarm_enabled ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc1_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_lock ; 
 int rtc_tm_to_time64 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int vr41xx_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
	time64_t alarm_sec;

	alarm_sec = rtc_tm_to_time64(&wkalrm->time);

	spin_lock_irq(&rtc_lock);

	if (alarm_enabled)
		disable_irq(aie_irq);

	rtc1_write(ECMPLREG, (uint16_t)(alarm_sec << 15));
	rtc1_write(ECMPMREG, (uint16_t)(alarm_sec >> 1));
	rtc1_write(ECMPHREG, (uint16_t)(alarm_sec >> 17));

	if (wkalrm->enabled)
		enable_irq(aie_irq);

	alarm_enabled = wkalrm->enabled;

	spin_unlock_irq(&rtc_lock);

	return 0;
}