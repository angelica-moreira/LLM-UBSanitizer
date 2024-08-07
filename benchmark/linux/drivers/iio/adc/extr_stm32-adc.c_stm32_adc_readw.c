#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct stm32_adc {scalar_t__ offset; TYPE_1__* common; } ;
struct TYPE_2__ {scalar_t__ base; } ;

/* Variables and functions */
 int /*<<< orphan*/  readw_relaxed (scalar_t__) ; 

__attribute__((used)) static u16 stm32_adc_readw(struct stm32_adc *adc, u32 reg)
{
	return readw_relaxed(adc->common->base + adc->offset + reg);
}