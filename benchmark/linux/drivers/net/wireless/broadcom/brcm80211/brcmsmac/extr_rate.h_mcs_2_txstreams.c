#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
struct TYPE_2__ {size_t tx_phy_ctl3; } ;

/* Variables and functions */
 size_t MCS_TXS_MASK ; 
 size_t MCS_TXS_SHIFT ; 
 TYPE_1__* mcs_table ; 

__attribute__((used)) static inline u8 mcs_2_txstreams(u8 mcs)
{
	return (mcs_table[mcs].tx_phy_ctl3 & MCS_TXS_MASK) >> MCS_TXS_SHIFT;
}