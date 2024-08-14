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
struct exynos_tmu_data {scalar_t__ base; } ;

/* Variables and functions */
 int ENODATA ; 
 scalar_t__ EXYNOS_TMU_REG_CURRENT_TEMP ; 
 int readb (scalar_t__) ; 

__attribute__((used)) static int exynos4210_tmu_read(struct exynos_tmu_data *data)
{
	int ret = readb(data->base + EXYNOS_TMU_REG_CURRENT_TEMP);

	/* "temp_code" should range between 75 and 175 */
	return (ret < 75 || ret > 175) ? -ENODATA : ret;
}