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
typedef  int /*<<< orphan*/  suspend_state_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_cluster_pm_enter () ; 
 int /*<<< orphan*/  cpu_cluster_pm_exit () ; 
 int /*<<< orphan*/  cpu_pm_enter () ; 
 int /*<<< orphan*/  cpu_pm_exit () ; 
 int /*<<< orphan*/  cpu_suspend (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  highbank_suspend_finish ; 

__attribute__((used)) static int highbank_pm_enter(suspend_state_t state)
{
	cpu_pm_enter();
	cpu_cluster_pm_enter();

	cpu_suspend(0, highbank_suspend_finish);

	cpu_cluster_pm_exit();
	cpu_pm_exit();

	return 0;
}