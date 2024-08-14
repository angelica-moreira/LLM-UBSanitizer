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
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int regmap_raw_write (void*,unsigned int,int /*<<< orphan*/  const*,size_t) ; 

__attribute__((used)) static int sigmadsp_write_regmap(void *control_data,
	unsigned int addr, const uint8_t data[], size_t len)
{
	return regmap_raw_write(control_data, addr,
		data, len);
}