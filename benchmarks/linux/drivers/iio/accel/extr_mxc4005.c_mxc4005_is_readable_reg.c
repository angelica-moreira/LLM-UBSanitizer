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
#define  MXC4005_REG_CONTROL 135 
#define  MXC4005_REG_DEVICE_ID 134 
#define  MXC4005_REG_XOUT_LOWER 133 
#define  MXC4005_REG_XOUT_UPPER 132 
#define  MXC4005_REG_YOUT_LOWER 131 
#define  MXC4005_REG_YOUT_UPPER 130 
#define  MXC4005_REG_ZOUT_LOWER 129 
#define  MXC4005_REG_ZOUT_UPPER 128 

__attribute__((used)) static bool mxc4005_is_readable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MXC4005_REG_XOUT_UPPER:
	case MXC4005_REG_XOUT_LOWER:
	case MXC4005_REG_YOUT_UPPER:
	case MXC4005_REG_YOUT_LOWER:
	case MXC4005_REG_ZOUT_UPPER:
	case MXC4005_REG_ZOUT_LOWER:
	case MXC4005_REG_DEVICE_ID:
	case MXC4005_REG_CONTROL:
		return true;
	default:
		return false;
	}
}