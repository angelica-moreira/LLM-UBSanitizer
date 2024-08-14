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
struct hinic_hwif {int dummy; } ;
typedef  enum hinic_outbound_state { ____Placeholder_hinic_outbound_state } hinic_outbound_state ;

/* Variables and functions */
 int /*<<< orphan*/  HINIC_CSR_FUNC_ATTR4_ADDR ; 
 int /*<<< orphan*/  HINIC_FA4_CLEAR (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HINIC_FA4_SET (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OUTBOUND_STATE ; 
 int /*<<< orphan*/  hinic_hwif_read_reg (struct hinic_hwif*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hinic_hwif_write_reg (struct hinic_hwif*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void hinic_outbound_state_set(struct hinic_hwif *hwif,
			      enum hinic_outbound_state outbound_state)
{
	u32 attr4 = hinic_hwif_read_reg(hwif, HINIC_CSR_FUNC_ATTR4_ADDR);

	attr4 = HINIC_FA4_CLEAR(attr4, OUTBOUND_STATE);
	attr4 |= HINIC_FA4_SET(outbound_state, OUTBOUND_STATE);

	hinic_hwif_write_reg(hwif, HINIC_CSR_FUNC_ATTR4_ADDR, attr4);
}