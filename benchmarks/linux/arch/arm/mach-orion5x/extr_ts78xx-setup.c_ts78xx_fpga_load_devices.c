#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int present; } ;
struct TYPE_6__ {int present; } ;
struct TYPE_9__ {int present; } ;
struct TYPE_8__ {TYPE_2__ ts_rng; TYPE_1__ ts_nand; TYPE_4__ ts_rtc; } ;
struct TYPE_10__ {TYPE_3__ supports; } ;

/* Variables and functions */
 TYPE_5__ ts78xx_fpga ; 
 int ts78xx_ts_nand_load () ; 
 int ts78xx_ts_rng_load () ; 
 int ts78xx_ts_rtc_load () ; 

__attribute__((used)) static int ts78xx_fpga_load_devices(void)
{
	int tmp, ret = 0;

	if (ts78xx_fpga.supports.ts_rtc.present == 1) {
		tmp = ts78xx_ts_rtc_load();
		if (tmp)
			ts78xx_fpga.supports.ts_rtc.present = 0;
		ret |= tmp;
	}
	if (ts78xx_fpga.supports.ts_nand.present == 1) {
		tmp = ts78xx_ts_nand_load();
		if (tmp)
			ts78xx_fpga.supports.ts_nand.present = 0;
		ret |= tmp;
	}
	if (ts78xx_fpga.supports.ts_rng.present == 1) {
		tmp = ts78xx_ts_rng_load();
		if (tmp)
			ts78xx_fpga.supports.ts_rng.present = 0;
		ret |= tmp;
	}

	return ret;
}