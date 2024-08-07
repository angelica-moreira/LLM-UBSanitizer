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
typedef  int u32 ;
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int rv6xx_clocks_per_unit (int) ; 

__attribute__((used)) static u32 rv6xx_scale_count_given_unit(struct radeon_device *rdev,
					u32 unscaled_count, u32 unit)
{
	u32 count_per_unit = rv6xx_clocks_per_unit(unit);

	return (unscaled_count + count_per_unit - 1) / count_per_unit;
}