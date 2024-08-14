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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct rtsx_chip {int dummy; } ;

/* Variables and functions */
 scalar_t__ CFGADDR0 ; 
 scalar_t__ CFGADDR1 ; 
 scalar_t__ CFGDATA0 ; 
 scalar_t__ CFGRWCTL ; 
 int MAX_RW_REG_CNT ; 
 int STATUS_SUCCESS ; 
 int rtsx_read_register (struct rtsx_chip*,scalar_t__,int*) ; 
 int rtsx_write_register (struct rtsx_chip*,scalar_t__,int,int) ; 

int rtsx_read_cfg_dw(struct rtsx_chip *chip, u8 func_no, u16 addr, u32 *val)
{
	int retval;
	int i;
	u8 tmp;
	u32 data = 0;

	retval = rtsx_write_register(chip, CFGADDR0, 0xFF, (u8)addr);
	if (retval)
		return retval;
	retval = rtsx_write_register(chip, CFGADDR1, 0xFF, (u8)(addr >> 8));
	if (retval)
		return retval;
	retval = rtsx_write_register(chip, CFGRWCTL, 0xFF,
				     0x80 | ((func_no & 0x03) << 4));
	if (retval)
		return retval;

	for (i = 0; i < MAX_RW_REG_CNT; i++) {
		retval = rtsx_read_register(chip, CFGRWCTL, &tmp);
		if (retval)
			return retval;
		if ((tmp & 0x80) == 0)
			break;
	}

	for (i = 0; i < 4; i++) {
		retval = rtsx_read_register(chip, CFGDATA0 + i, &tmp);
		if (retval)
			return retval;
		data |= (u32)tmp << (i * 8);
	}

	if (val)
		*val = data;

	return STATUS_SUCCESS;
}