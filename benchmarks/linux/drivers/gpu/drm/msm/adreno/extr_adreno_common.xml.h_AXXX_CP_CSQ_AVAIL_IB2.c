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
 int AXXX_CP_CSQ_AVAIL_IB2__MASK ; 
 int AXXX_CP_CSQ_AVAIL_IB2__SHIFT ; 

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_AVAIL_IB2(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_AVAIL_IB2__SHIFT) & AXXX_CP_CSQ_AVAIL_IB2__MASK;
}