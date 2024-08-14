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
typedef  int u32 ;

/* Variables and functions */
 int /*<<< orphan*/  VIASR ; 
 int /*<<< orphan*/  via_write_reg (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  via_write_reg_mask (int /*<<< orphan*/ ,int,int,int) ; 

__attribute__((used)) static inline void set_engine_pll_encoded(u32 data)
{
	via_write_reg_mask(VIASR, 0x40, 0x01, 0x01); /* enable reset */
	via_write_reg(VIASR, 0x47, data & 0xFF);
	via_write_reg(VIASR, 0x48, (data >> 8) & 0xFF);
	via_write_reg(VIASR, 0x49, (data >> 16) & 0xFF);
	via_write_reg_mask(VIASR, 0x40, 0x00, 0x01); /* disable reset */
}