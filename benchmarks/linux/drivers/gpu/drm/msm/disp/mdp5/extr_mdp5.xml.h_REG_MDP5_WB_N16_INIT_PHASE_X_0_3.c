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
typedef  scalar_t__ uint32_t ;

/* Variables and functions */
 scalar_t__ __offset_WB (scalar_t__) ; 

__attribute__((used)) static inline uint32_t REG_MDP5_WB_N16_INIT_PHASE_X_0_3(uint32_t i0) { return 0x00000060 + __offset_WB(i0); }