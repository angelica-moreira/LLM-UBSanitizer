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
typedef  int /*<<< orphan*/  u8 ;
struct pcf50633 {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int regmap_raw_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

int pcf50633_write_block(struct pcf50633 *pcf , u8 reg,
					int nr_regs, u8 *data)
{
	return regmap_raw_write(pcf->regmap, reg, data, nr_regs);
}