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
struct snd_soc_dapm_context {int /*<<< orphan*/  component; } ;

/* Variables and functions */
 int EIO ; 
 int snd_soc_component_test_bits (int /*<<< orphan*/ ,int,unsigned int,unsigned int) ; 

__attribute__((used)) static int soc_dapm_test_bits(struct snd_soc_dapm_context *dapm,
	int reg, unsigned int mask, unsigned int value)
{
	if (!dapm->component)
		return -EIO;
	return snd_soc_component_test_bits(dapm->component, reg, mask, value);
}