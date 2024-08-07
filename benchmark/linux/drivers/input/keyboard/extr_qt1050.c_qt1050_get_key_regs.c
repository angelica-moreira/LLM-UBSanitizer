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
struct qt1050_key_regs {int dummy; } ;

/* Variables and functions */
 struct qt1050_key_regs const* qt1050_key_regs_data ; 

__attribute__((used)) static const struct qt1050_key_regs *qt1050_get_key_regs(int key_num)
{
	return &qt1050_key_regs_data[key_num];
}