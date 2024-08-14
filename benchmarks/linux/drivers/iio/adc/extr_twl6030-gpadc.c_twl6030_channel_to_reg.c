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
typedef  scalar_t__ u8 ;

/* Variables and functions */
 scalar_t__ TWL6030_GPADC_GPCH0_LSB ; 

__attribute__((used)) static u8 twl6030_channel_to_reg(int channel)
{
	return TWL6030_GPADC_GPCH0_LSB + 2 * channel;
}