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
typedef  size_t uint32_t ;
struct smu_context {int dummy; } ;
struct smu_11_0_cmn2aisc_mapping {int map_to; int /*<<< orphan*/  valid_mapping; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t SMU_POWER_SOURCE_COUNT ; 
 struct smu_11_0_cmn2aisc_mapping* vega20_pwr_src_map ; 

__attribute__((used)) static int vega20_get_pwr_src_index(struct smu_context *smc, uint32_t index)
{
	struct smu_11_0_cmn2aisc_mapping mapping;

	if (index >= SMU_POWER_SOURCE_COUNT)
		return -EINVAL;

	mapping = vega20_pwr_src_map[index];
	if (!(mapping.valid_mapping)) {
		return -EINVAL;
	}

	return mapping.map_to;
}