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
struct rt5677_priv {int dummy; } ;

/* Variables and functions */
 int rt5677_dsp_mode_i2c_read_addr (struct rt5677_priv*,int,unsigned int*) ; 

__attribute__((used)) static int rt5677_dsp_mode_i2c_read(
	struct rt5677_priv *rt5677, unsigned int reg, unsigned int *value)
{
	int ret = rt5677_dsp_mode_i2c_read_addr(rt5677, 0x18020000 + reg * 2,
		value);

	*value &= 0xffff;

	return ret;
}