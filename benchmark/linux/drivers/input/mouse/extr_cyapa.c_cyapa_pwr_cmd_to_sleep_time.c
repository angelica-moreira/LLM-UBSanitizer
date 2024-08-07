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
typedef  int u16 ;

/* Variables and functions */

u16 cyapa_pwr_cmd_to_sleep_time(u8 pwr_mode)
{
	u8 encoded_time = pwr_mode >> 2;

	return (encoded_time < 10) ? encoded_time * 10
				   : (encoded_time - 5) * 20;
}