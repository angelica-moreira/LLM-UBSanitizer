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
#define  PCM3168A_ADC_OV 129 
#define  PCM3168A_DAC_ZERO 128 

__attribute__((used)) static bool pcm3168a_volatile_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case PCM3168A_DAC_ZERO:
	case PCM3168A_ADC_OV:
		return true;
	default:
		return false;
	}
}