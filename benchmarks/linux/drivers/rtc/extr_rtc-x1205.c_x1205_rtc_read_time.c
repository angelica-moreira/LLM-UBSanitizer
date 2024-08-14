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
struct rtc_time {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  X1205_CCR_BASE ; 
 int /*<<< orphan*/  to_i2c_client (struct device*) ; 
 int x1205_get_datetime (int /*<<< orphan*/ ,struct rtc_time*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int x1205_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	return x1205_get_datetime(to_i2c_client(dev),
		tm, X1205_CCR_BASE);
}