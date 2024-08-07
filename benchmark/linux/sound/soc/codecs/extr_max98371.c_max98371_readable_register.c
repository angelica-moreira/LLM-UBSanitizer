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
#define  MAX98371_SOFT_RESET 128 

__attribute__((used)) static bool max98371_readable_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MAX98371_SOFT_RESET:
		return false;
	default:
		return true;
	}
}