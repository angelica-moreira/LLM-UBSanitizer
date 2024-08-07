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
typedef  enum a3xx_repl_mode { ____Placeholder_a3xx_repl_mode } a3xx_repl_mode ;

/* Variables and functions */
 int A3XX_VPC_VARYING_PS_REPL_MODE_CA__MASK ; 
 int A3XX_VPC_VARYING_PS_REPL_MODE_CA__SHIFT ; 

__attribute__((used)) static inline uint32_t A3XX_VPC_VARYING_PS_REPL_MODE_CA(enum a3xx_repl_mode val)
{
	return ((val) << A3XX_VPC_VARYING_PS_REPL_MODE_CA__SHIFT) & A3XX_VPC_VARYING_PS_REPL_MODE_CA__MASK;
}