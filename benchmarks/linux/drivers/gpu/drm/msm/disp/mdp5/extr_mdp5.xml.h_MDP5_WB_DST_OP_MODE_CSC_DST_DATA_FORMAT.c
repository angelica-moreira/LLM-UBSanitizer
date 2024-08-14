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
 int MDP5_WB_DST_OP_MODE_CSC_DST_DATA_FORMAT__MASK ; 
 int MDP5_WB_DST_OP_MODE_CSC_DST_DATA_FORMAT__SHIFT ; 

__attribute__((used)) static inline uint32_t MDP5_WB_DST_OP_MODE_CSC_DST_DATA_FORMAT(uint32_t val)
{
	return ((val) << MDP5_WB_DST_OP_MODE_CSC_DST_DATA_FORMAT__SHIFT) & MDP5_WB_DST_OP_MODE_CSC_DST_DATA_FORMAT__MASK;
}