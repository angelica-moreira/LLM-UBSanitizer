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
typedef  int uint32_t ;

/* Variables and functions */
 int DSI_28nm_PHY_PLL_SDM_CFG2_FREQ_SEED_7_0__MASK ; 
 int DSI_28nm_PHY_PLL_SDM_CFG2_FREQ_SEED_7_0__SHIFT ; 

__attribute__((used)) static inline uint32_t DSI_28nm_PHY_PLL_SDM_CFG2_FREQ_SEED_7_0(uint32_t val)
{
	return ((val) << DSI_28nm_PHY_PLL_SDM_CFG2_FREQ_SEED_7_0__SHIFT) & DSI_28nm_PHY_PLL_SDM_CFG2_FREQ_SEED_7_0__MASK;
}