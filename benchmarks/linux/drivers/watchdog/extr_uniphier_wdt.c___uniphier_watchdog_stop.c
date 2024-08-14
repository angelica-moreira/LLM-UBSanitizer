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
struct regmap {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WDTCTRL ; 
 int /*<<< orphan*/  WDTCTRL_ENABLE ; 
 int regmap_write_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int __uniphier_watchdog_stop(struct regmap *regmap)
{
	/* Disable and stop watchdog */
	return regmap_write_bits(regmap, WDTCTRL, WDTCTRL_ENABLE, 0);
}