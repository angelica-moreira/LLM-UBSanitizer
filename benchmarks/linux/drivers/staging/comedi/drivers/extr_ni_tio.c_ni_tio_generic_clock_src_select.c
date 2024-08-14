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
struct ni_gpct {TYPE_1__* counter_dev; } ;
struct TYPE_2__ {int variant; } ;

/* Variables and functions */
 int ni_660x_clock_src_select (struct ni_gpct const*,unsigned int*) ; 
#define  ni_gpct_variant_660x 130 
#define  ni_gpct_variant_e_series 129 
#define  ni_gpct_variant_m_series 128 
 int ni_m_series_clock_src_select (struct ni_gpct const*,unsigned int*) ; 

__attribute__((used)) static int ni_tio_generic_clock_src_select(const struct ni_gpct *counter,
					   unsigned int *clk_src)
{
	switch (counter->counter_dev->variant) {
	case ni_gpct_variant_e_series:
	case ni_gpct_variant_m_series:
	default:
		return ni_m_series_clock_src_select(counter, clk_src);
	case ni_gpct_variant_660x:
		return ni_660x_clock_src_select(counter, clk_src);
	}
}