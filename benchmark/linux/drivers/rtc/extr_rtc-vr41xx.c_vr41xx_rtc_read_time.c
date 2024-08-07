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
typedef  scalar_t__ time64_t ;
struct rtc_time {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  epoch ; 
 scalar_t__ mktime64 (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ read_elapsed_second () ; 
 int /*<<< orphan*/  rtc_time64_to_tm (scalar_t__,struct rtc_time*) ; 

__attribute__((used)) static int vr41xx_rtc_read_time(struct device *dev, struct rtc_time *time)
{
	time64_t epoch_sec, elapsed_sec;

	epoch_sec = mktime64(epoch, 1, 1, 0, 0, 0);
	elapsed_sec = read_elapsed_second();

	rtc_time64_to_tm(epoch_sec + elapsed_sec, time);

	return 0;
}