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
 int CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO__MASK ; 
 int CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO__SHIFT ; 

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO__SHIFT) & CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO__MASK;
}