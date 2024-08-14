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
 int /*<<< orphan*/ * W83773_STATUS ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 

__attribute__((used)) static int get_fault(struct regmap *regmap, int index, long *val)
{
	unsigned int regval;
	int ret;

	ret = regmap_read(regmap, W83773_STATUS[index], &regval);
	if (ret < 0)
		return ret;

	*val = (regval & 0x04) >> 2;
	return 0;
}