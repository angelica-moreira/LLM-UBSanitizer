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
typedef  enum mdp5_igc_type { ____Placeholder_mdp5_igc_type } mdp5_igc_type ;

/* Variables and functions */
 int __offset_IGC (int) ; 

__attribute__((used)) static inline uint32_t REG_MDP5_IGC_LUT(enum mdp5_igc_type i0, uint32_t i1) { return 0x00000000 + __offset_IGC(i0) + 0x4*i1; }