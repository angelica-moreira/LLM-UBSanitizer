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
 unsigned int REGULATOR_MODE_FAST ; 
 unsigned int REGULATOR_MODE_IDLE ; 
 unsigned int REGULATOR_MODE_INVALID ; 
 unsigned int REGULATOR_MODE_NORMAL ; 
#define  RPMH_REGULATOR_MODE_AUTO 130 
#define  RPMH_REGULATOR_MODE_HPM 129 
#define  RPMH_REGULATOR_MODE_LPM 128 

__attribute__((used)) static unsigned int rpmh_regulator_pmic4_bob_of_map_mode(unsigned int rpmh_mode)
{
	unsigned int mode;

	switch (rpmh_mode) {
	case RPMH_REGULATOR_MODE_HPM:
		mode = REGULATOR_MODE_FAST;
		break;
	case RPMH_REGULATOR_MODE_AUTO:
		mode = REGULATOR_MODE_NORMAL;
		break;
	case RPMH_REGULATOR_MODE_LPM:
		mode = REGULATOR_MODE_IDLE;
		break;
	default:
		mode = REGULATOR_MODE_INVALID;
		break;
	}

	return mode;
}