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
typedef  int uint32_t ;

/* Variables and functions */
 int IDT_VENDOR_ID ; 

__attribute__((used)) static int device_needs_bus_num_war(uint32_t deviceid)
{
#define IDT_VENDOR_ID 0x111d

	if ((deviceid  & 0xffff) == IDT_VENDOR_ID)
		return 1;
	return 0;
}