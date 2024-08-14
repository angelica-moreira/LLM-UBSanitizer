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
struct ov7251 {int /*<<< orphan*/  timing_format2; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int /*<<< orphan*/  OV7251_TIMING_FORMAT2 ; 
 int /*<<< orphan*/  OV7251_TIMING_FORMAT2_MIRROR ; 
 int ov7251_write_reg (struct ov7251*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ov7251_set_hflip(struct ov7251 *ov7251, s32 value)
{
	u8 val = ov7251->timing_format2;
	int ret;

	if (value)
		val |= OV7251_TIMING_FORMAT2_MIRROR;
	else
		val &= ~OV7251_TIMING_FORMAT2_MIRROR;

	ret = ov7251_write_reg(ov7251, OV7251_TIMING_FORMAT2, val);
	if (!ret)
		ov7251->timing_format2 = val;

	return ret;
}