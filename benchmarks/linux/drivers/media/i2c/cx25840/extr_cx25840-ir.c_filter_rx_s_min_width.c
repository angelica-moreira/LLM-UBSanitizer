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
typedef  int /*<<< orphan*/  u32 ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CX25840_IR_FILTR_REG ; 
 int /*<<< orphan*/  cx25840_write4 (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lpf_count_to_ns (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ns_to_lpf_count (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 filter_rx_s_min_width(struct i2c_client *c, u32 min_width_ns)
{
	u32 count = ns_to_lpf_count(min_width_ns);
	cx25840_write4(c, CX25840_IR_FILTR_REG, count);
	return lpf_count_to_ns(count);
}