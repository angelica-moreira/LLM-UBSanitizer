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
 int VMCS_FIELD_WIDTH_U32 ; 

__attribute__((used)) static inline int vmcs_field_width(unsigned long field)
{
	if (0x1 & field)	/* the *_HIGH fields are all 32 bit */
		return VMCS_FIELD_WIDTH_U32;
	return (field >> 13) & 0x3;
}