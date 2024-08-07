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
typedef  size_t u32 ;
struct TYPE_2__ {int /*<<< orphan*/  clk_name; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  MAX_NAME_LEN ; 
 TYPE_1__* clock ; 
 int /*<<< orphan*/  strncpy (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int zynqmp_is_valid_clock (size_t) ; 

__attribute__((used)) static int zynqmp_get_clock_name(u32 clk_id, char *clk_name)
{
	int ret;

	ret = zynqmp_is_valid_clock(clk_id);
	if (ret == 1) {
		strncpy(clk_name, clock[clk_id].clk_name, MAX_NAME_LEN);
		return 0;
	}

	return ret == 0 ? -EINVAL : ret;
}