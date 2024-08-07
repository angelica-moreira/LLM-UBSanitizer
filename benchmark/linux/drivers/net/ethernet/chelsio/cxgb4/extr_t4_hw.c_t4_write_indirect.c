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
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  t4_write_reg (struct adapter*,unsigned int,int /*<<< orphan*/ ) ; 

void t4_write_indirect(struct adapter *adap, unsigned int addr_reg,
		       unsigned int data_reg, const u32 *vals,
		       unsigned int nregs, unsigned int start_idx)
{
	while (nregs--) {
		t4_write_reg(adap, addr_reg, start_idx++);
		t4_write_reg(adap, data_reg, *vals++);
	}
}