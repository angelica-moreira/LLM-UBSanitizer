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
 int /*<<< orphan*/  CH_ERR (struct adapter*,char*,unsigned int) ; 
 int EIO ; 
 int F_BUSY ; 
 int t3_read_reg (struct adapter*,unsigned int) ; 
 int /*<<< orphan*/  t3_write_reg (struct adapter*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int wrreg_wait(struct adapter *adapter, unsigned int addr, u32 val)
{
	t3_write_reg(adapter, addr, val);
	t3_read_reg(adapter, addr);	/* flush */
	if (!(t3_read_reg(adapter, addr) & F_BUSY))
		return 0;
	CH_ERR(adapter, "write to MC7 register 0x%x timed out\n", addr);
	return -EIO;
}