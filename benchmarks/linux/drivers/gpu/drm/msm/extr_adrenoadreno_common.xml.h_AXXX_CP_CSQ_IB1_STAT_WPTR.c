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
 int AXXX_CP_CSQ_IB1_STAT_WPTR__MASK ; 
 int AXXX_CP_CSQ_IB1_STAT_WPTR__SHIFT ; 

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_IB1_STAT_WPTR(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_IB1_STAT_WPTR__SHIFT) & AXXX_CP_CSQ_IB1_STAT_WPTR__MASK;
}