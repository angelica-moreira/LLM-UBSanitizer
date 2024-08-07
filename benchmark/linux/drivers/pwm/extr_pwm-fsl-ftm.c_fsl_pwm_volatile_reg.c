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
#define  FTM_CNT 130 
#define  FTM_FMS 129 
#define  FTM_MODE 128 

__attribute__((used)) static bool fsl_pwm_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case FTM_FMS:
	case FTM_MODE:
	case FTM_CNT:
		return true;
	}
	return false;
}