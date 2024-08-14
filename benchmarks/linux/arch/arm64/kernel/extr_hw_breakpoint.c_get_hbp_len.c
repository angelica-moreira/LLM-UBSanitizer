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

/* Variables and functions */
#define  ARM_BREAKPOINT_LEN_1 135 
#define  ARM_BREAKPOINT_LEN_2 134 
#define  ARM_BREAKPOINT_LEN_3 133 
#define  ARM_BREAKPOINT_LEN_4 132 
#define  ARM_BREAKPOINT_LEN_5 131 
#define  ARM_BREAKPOINT_LEN_6 130 
#define  ARM_BREAKPOINT_LEN_7 129 
#define  ARM_BREAKPOINT_LEN_8 128 

__attribute__((used)) static int get_hbp_len(u8 hbp_len)
{
	unsigned int len_in_bytes = 0;

	switch (hbp_len) {
	case ARM_BREAKPOINT_LEN_1:
		len_in_bytes = 1;
		break;
	case ARM_BREAKPOINT_LEN_2:
		len_in_bytes = 2;
		break;
	case ARM_BREAKPOINT_LEN_3:
		len_in_bytes = 3;
		break;
	case ARM_BREAKPOINT_LEN_4:
		len_in_bytes = 4;
		break;
	case ARM_BREAKPOINT_LEN_5:
		len_in_bytes = 5;
		break;
	case ARM_BREAKPOINT_LEN_6:
		len_in_bytes = 6;
		break;
	case ARM_BREAKPOINT_LEN_7:
		len_in_bytes = 7;
		break;
	case ARM_BREAKPOINT_LEN_8:
		len_in_bytes = 8;
		break;
	}

	return len_in_bytes;
}