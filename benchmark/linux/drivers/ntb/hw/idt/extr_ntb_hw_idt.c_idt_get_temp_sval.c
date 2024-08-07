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
typedef  int s8 ;

/* Variables and functions */

__attribute__((used)) static inline long idt_get_temp_sval(u32 data)
{
	return ((s8)data / 2) * 1000 + (data & 0x1 ? 500 : 0);
}