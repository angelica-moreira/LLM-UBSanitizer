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
struct stmp3xxx_rtc_data {scalar_t__ io; } ;
struct rtc_time {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 scalar_t__ STMP3XXX_RTC_SECONDS ; 
 struct stmp3xxx_rtc_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  rtc_time64_to_tm (int /*<<< orphan*/ ,struct rtc_time*) ; 
 int stmp3xxx_wait_time (struct stmp3xxx_rtc_data*) ; 

__attribute__((used)) static int stmp3xxx_rtc_gettime(struct device *dev, struct rtc_time *rtc_tm)
{
	int ret;
	struct stmp3xxx_rtc_data *rtc_data = dev_get_drvdata(dev);

	ret = stmp3xxx_wait_time(rtc_data);
	if (ret)
		return ret;

	rtc_time64_to_tm(readl(rtc_data->io + STMP3XXX_RTC_SECONDS), rtc_tm);
	return 0;
}