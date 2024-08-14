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

/* Variables and functions */
 int ADVERTISE_1000XPAUSE ; 
 int ADVERTISE_1000XPSE_ASYM ; 
 int FLOW_CTRL_RX ; 
 int FLOW_CTRL_TX ; 

__attribute__((used)) static u32 tg3_decode_flowctrl_1000X(u32 adv)
{
	u32 flowctrl = 0;

	if (adv & ADVERTISE_1000XPAUSE) {
		flowctrl |= FLOW_CTRL_RX;
		if (!(adv & ADVERTISE_1000XPSE_ASYM))
			flowctrl |= FLOW_CTRL_TX;
	} else if (adv & ADVERTISE_1000XPSE_ASYM)
		flowctrl |= FLOW_CTRL_TX;

	return flowctrl;
}