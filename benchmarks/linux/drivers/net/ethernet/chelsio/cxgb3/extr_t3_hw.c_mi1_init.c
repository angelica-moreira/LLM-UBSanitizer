#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct adapter_info {int dummy; } ;
struct TYPE_3__ {int cclk; int mdc; } ;
struct TYPE_4__ {TYPE_1__ vpd; } ;
struct adapter {TYPE_2__ params; } ;

/* Variables and functions */
 int /*<<< orphan*/  A_MI1_CFG ; 
 int F_PREEN ; 
 int V_CLKDIV (int) ; 
 int /*<<< orphan*/  t3_write_reg (struct adapter*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void mi1_init(struct adapter *adap, const struct adapter_info *ai)
{
	u32 clkdiv = adap->params.vpd.cclk / (2 * adap->params.vpd.mdc) - 1;
	u32 val = F_PREEN | V_CLKDIV(clkdiv);

	t3_write_reg(adap, A_MI1_CFG, val);
}