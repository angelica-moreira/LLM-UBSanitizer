#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_2__ {int /*<<< orphan*/  regmap; } ;
struct rt1711h_chip {TYPE_1__ data; } ;

/* Variables and functions */
 int regmap_raw_read (int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int rt1711h_read8(struct rt1711h_chip *chip, unsigned int reg, u8 *val)
{
	return regmap_raw_read(chip->data.regmap, reg, val, sizeof(u8));
}