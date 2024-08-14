#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int init; } ;
struct TYPE_5__ {TYPE_1__ ts_rtc; } ;
struct TYPE_6__ {TYPE_2__ supports; } ;

/* Variables and functions */
 int platform_device_add (int /*<<< orphan*/ *) ; 
 int platform_device_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*,int) ; 
 TYPE_3__ ts78xx_fpga ; 
 int /*<<< orphan*/  ts78xx_ts_rtc_device ; 

__attribute__((used)) static int ts78xx_ts_rtc_load(void)
{
	int rc;

	if (ts78xx_fpga.supports.ts_rtc.init == 0) {
		rc = platform_device_register(&ts78xx_ts_rtc_device);
		if (!rc)
			ts78xx_fpga.supports.ts_rtc.init = 1;
	} else {
		rc = platform_device_add(&ts78xx_ts_rtc_device);
	}

	if (rc)
		pr_info("RTC could not be registered: %d\n", rc);

	return rc;
}