#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ irq; } ;

/* Variables and functions */
 scalar_t__ cp0_perfcount_irq ; 
 int /*<<< orphan*/  free_irq (scalar_t__,TYPE_1__*) ; 
 TYPE_1__ mipspmu ; 
 int /*<<< orphan*/  perf_irq ; 
 int /*<<< orphan*/  save_perf_irq ; 

__attribute__((used)) static void mipspmu_free_irq(void)
{
	if (mipspmu.irq >= 0)
		free_irq(mipspmu.irq, &mipspmu);
	else if (cp0_perfcount_irq < 0)
		perf_irq = save_perf_irq;
}