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
typedef  enum a3xx_vtx_fmt { ____Placeholder_a3xx_vtx_fmt } a3xx_vtx_fmt ;

/* Variables and functions */
 int A3XX_VFD_DECODE_INSTR_FORMAT__MASK ; 
 int A3XX_VFD_DECODE_INSTR_FORMAT__SHIFT ; 

__attribute__((used)) static inline uint32_t A3XX_VFD_DECODE_INSTR_FORMAT(enum a3xx_vtx_fmt val)
{
	return ((val) << A3XX_VFD_DECODE_INSTR_FORMAT__SHIFT) & A3XX_VFD_DECODE_INSTR_FORMAT__MASK;
}