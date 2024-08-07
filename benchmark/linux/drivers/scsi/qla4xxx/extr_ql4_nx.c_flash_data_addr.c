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
typedef  int uint32_t ;
struct ql82xx_hw_data {int flash_data_off; } ;

/* Variables and functions */

__attribute__((used)) static inline uint32_t
flash_data_addr(struct ql82xx_hw_data *hw, uint32_t faddr)
{
	return hw->flash_data_off | faddr;
}