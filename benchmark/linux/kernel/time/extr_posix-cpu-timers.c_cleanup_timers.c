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
struct posix_cputimers {TYPE_1__* bases; } ;
struct TYPE_2__ {int /*<<< orphan*/  tqhead; } ;

/* Variables and functions */
 size_t CPUCLOCK_PROF ; 
 size_t CPUCLOCK_SCHED ; 
 size_t CPUCLOCK_VIRT ; 
 int /*<<< orphan*/  cleanup_timerqueue (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void cleanup_timers(struct posix_cputimers *pct)
{
	cleanup_timerqueue(&pct->bases[CPUCLOCK_PROF].tqhead);
	cleanup_timerqueue(&pct->bases[CPUCLOCK_VIRT].tqhead);
	cleanup_timerqueue(&pct->bases[CPUCLOCK_SCHED].tqhead);
}