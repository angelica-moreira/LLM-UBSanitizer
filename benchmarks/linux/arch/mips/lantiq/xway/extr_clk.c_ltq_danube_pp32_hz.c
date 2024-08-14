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
 int /*<<< orphan*/  CGU_SYS ; 
 unsigned long CLOCK_133M ; 
 unsigned long CLOCK_222M ; 
 unsigned long CLOCK_240M ; 
 unsigned long CLOCK_266M ; 
 int ltq_cgu_r32 (int /*<<< orphan*/ ) ; 

unsigned long ltq_danube_pp32_hz(void)
{
	unsigned int clksys = (ltq_cgu_r32(CGU_SYS) >> 7) & 3;
	unsigned long clk;

	switch (clksys) {
	case 1:
		clk = CLOCK_240M;
		break;
	case 2:
		clk = CLOCK_222M;
		break;
	case 3:
		clk = CLOCK_133M;
		break;
	default:
		clk = CLOCK_266M;
		break;
	}

	return clk;
}