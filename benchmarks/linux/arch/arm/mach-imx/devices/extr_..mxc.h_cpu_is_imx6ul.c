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
 scalar_t__ MXC_CPU_IMX6UL ; 
 scalar_t__ __mxc_cpu_type ; 

__attribute__((used)) static inline bool cpu_is_imx6ul(void)
{
	return __mxc_cpu_type == MXC_CPU_IMX6UL;
}