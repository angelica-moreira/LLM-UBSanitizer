#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* states; } ;
struct TYPE_3__ {int disabled; } ;

/* Variables and functions */
 TYPE_2__ imx6q_cpuidle_driver ; 

void imx6q_cpuidle_fec_irqs_unused(void)
{
	imx6q_cpuidle_driver.states[1].disabled = false;
}