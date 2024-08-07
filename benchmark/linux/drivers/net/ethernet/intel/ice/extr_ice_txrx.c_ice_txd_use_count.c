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

/* Variables and functions */
 unsigned int ICE_DESCS_FOR_SKB_DATA_PTR ; 

__attribute__((used)) static unsigned int ice_txd_use_count(unsigned int size)
{
	return ((size * 85) >> 20) + ICE_DESCS_FOR_SKB_DATA_PTR;
}