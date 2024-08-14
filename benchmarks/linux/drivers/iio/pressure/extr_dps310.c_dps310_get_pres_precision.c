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
struct dps310_data {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  DPS310_PRS_CFG ; 
 int GENMASK (int,int /*<<< orphan*/ ) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int dps310_get_pres_precision(struct dps310_data *data)
{
	int rc;
	int val;

	rc = regmap_read(data->regmap, DPS310_PRS_CFG, &val);
	if (rc < 0)
		return rc;

	return BIT(val & GENMASK(2, 0));
}