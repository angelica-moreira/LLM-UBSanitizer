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
struct op_register_config {int reset_values; } ;

/* Variables and functions */
 int /*<<< orphan*/  wrperfmon (int,int) ; 

__attribute__((used)) static void
ev6_reset_ctr(struct op_register_config *reg, unsigned long ctr)
{
	wrperfmon(6, reg->reset_values | (1 << ctr));
}