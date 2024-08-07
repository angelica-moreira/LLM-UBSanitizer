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
struct hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO_DATA ; 
 int hw_read_20kx (struct hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hw_write_20kx (struct hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static void hw_dac_stop(struct hw *hw)
{
	u32 data;
	data = hw_read_20kx(hw, GPIO_DATA);
	data &= 0xFFFFFFFD;
	hw_write_20kx(hw, GPIO_DATA, data);
	usleep_range(10000, 11000);
}