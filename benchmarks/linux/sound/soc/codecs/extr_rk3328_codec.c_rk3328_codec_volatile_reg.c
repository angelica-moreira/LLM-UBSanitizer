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
struct device {int dummy; } ;

/* Variables and functions */
#define  CODEC_RESET 128 

__attribute__((used)) static bool rk3328_codec_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case CODEC_RESET:
		return true;
	default:
		return false;
	}
}