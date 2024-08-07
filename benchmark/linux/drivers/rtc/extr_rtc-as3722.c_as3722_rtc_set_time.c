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
typedef  int /*<<< orphan*/  u8 ;
struct rtc_time {int tm_year; } ;
struct device {int dummy; } ;
struct as3722_rtc {struct as3722* as3722; } ;
struct as3722 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AS3722_RTC_SECOND_REG ; 
 int AS3722_RTC_START_YEAR ; 
 int EINVAL ; 
 int as3722_block_write (struct as3722*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  as3722_time_to_reg (int /*<<< orphan*/ *,struct rtc_time*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct as3722_rtc* dev_get_drvdata (struct device*) ; 

__attribute__((used)) static int as3722_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct as3722_rtc *as3722_rtc = dev_get_drvdata(dev);
	struct as3722 *as3722 = as3722_rtc->as3722;
	u8 as_time_array[6];
	int ret;

	if (tm->tm_year < (AS3722_RTC_START_YEAR - 1900))
		return -EINVAL;

	as3722_time_to_reg(as_time_array, tm);
	ret = as3722_block_write(as3722, AS3722_RTC_SECOND_REG, 6,
			as_time_array);
	if (ret < 0)
		dev_err(dev, "RTC_SECOND reg block write failed %d\n", ret);
	return ret;
}