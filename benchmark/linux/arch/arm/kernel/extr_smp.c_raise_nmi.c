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
typedef  int /*<<< orphan*/  cpumask_t ;

/* Variables and functions */
 int /*<<< orphan*/  IPI_CPU_BACKTRACE ; 
 int /*<<< orphan*/  __smp_cross_call (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void raise_nmi(cpumask_t *mask)
{
	__smp_cross_call(mask, IPI_CPU_BACKTRACE);
}