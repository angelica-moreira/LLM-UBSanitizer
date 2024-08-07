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
typedef  int uint8_t ;
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 

__attribute__((used)) static inline uint32_t set_reg_field_value_ex(
	uint32_t reg_value,
	uint32_t value,
	uint32_t mask,
	uint8_t shift)
{
	ASSERT(mask != 0);
	return (reg_value & ~mask) | (mask & (value << shift));
}