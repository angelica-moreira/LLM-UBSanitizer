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
typedef  int insn_attr_t ;

/* Variables and functions */
 int INAT_PFX_MASK ; 
 int INAT_PFX_VEX3 ; 

__attribute__((used)) static inline int inat_is_vex3_prefix(insn_attr_t attr)
{
	return (attr & INAT_PFX_MASK) == INAT_PFX_VEX3;
}