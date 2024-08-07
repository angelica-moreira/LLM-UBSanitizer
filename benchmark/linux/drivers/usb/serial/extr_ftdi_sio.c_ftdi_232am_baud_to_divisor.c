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

/* Variables and functions */
 unsigned short ftdi_232am_baud_base_to_divisor (int,int) ; 

__attribute__((used)) static unsigned short int ftdi_232am_baud_to_divisor(int baud)
{
	 return ftdi_232am_baud_base_to_divisor(baud, 48000000);
}