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
struct psb_intel_sdvo {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SDVO_CMD_SET_CONTROL_BUS_SWITCH ; 
 int psb_intel_sdvo_write_cmd (struct psb_intel_sdvo*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static bool psb_intel_sdvo_set_control_bus_switch(struct psb_intel_sdvo *psb_intel_sdvo,
					      u8 ddc_bus)
{
	/* This must be the immediately preceding write before the i2c xfer */
	return psb_intel_sdvo_write_cmd(psb_intel_sdvo,
				    SDVO_CMD_SET_CONTROL_BUS_SWITCH,
				    &ddc_bus, 1);
}