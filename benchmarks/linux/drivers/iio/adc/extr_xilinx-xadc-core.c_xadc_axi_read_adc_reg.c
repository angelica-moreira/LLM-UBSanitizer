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
typedef  int uint16_t ;
struct xadc {int dummy; } ;

/* Variables and functions */
 scalar_t__ XADC_AXI_ADC_REG_OFFSET ; 
 int /*<<< orphan*/  xadc_read_reg (struct xadc*,scalar_t__,int*) ; 

__attribute__((used)) static int xadc_axi_read_adc_reg(struct xadc *xadc, unsigned int reg,
	uint16_t *val)
{
	uint32_t val32;

	xadc_read_reg(xadc, XADC_AXI_ADC_REG_OFFSET + reg * 4, &val32);
	*val = val32 & 0xffff;

	return 0;
}