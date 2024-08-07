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
 unsigned int INA2XX_CURRENT ; 
 unsigned int INA2XX_SHUNT_VOLTAGE ; 

__attribute__((used)) static inline bool is_signed_reg(unsigned int reg)
{
	return (reg == INA2XX_SHUNT_VOLTAGE) || (reg == INA2XX_CURRENT);
}