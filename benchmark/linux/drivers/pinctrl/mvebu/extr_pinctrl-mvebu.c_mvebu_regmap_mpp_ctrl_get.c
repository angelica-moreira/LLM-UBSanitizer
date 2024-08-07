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
struct TYPE_2__ {scalar_t__ offset; int /*<<< orphan*/  map; } ;
struct mvebu_mpp_ctrl_data {TYPE_1__ regmap; } ;

/* Variables and functions */
 unsigned int MVEBU_MPPS_PER_REG ; 
 unsigned int MVEBU_MPP_BITS ; 
 unsigned int MVEBU_MPP_MASK ; 
 int regmap_read (int /*<<< orphan*/ ,scalar_t__,unsigned int*) ; 

int mvebu_regmap_mpp_ctrl_get(struct mvebu_mpp_ctrl_data *data,
			      unsigned int pid, unsigned long *config)
{
	unsigned off = (pid / MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
	unsigned shift = (pid % MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
	unsigned int val;
	int err;

	err = regmap_read(data->regmap.map, data->regmap.offset + off, &val);
	if (err)
		return err;

	*config = (val >> shift) & MVEBU_MPP_MASK;

	return 0;
}