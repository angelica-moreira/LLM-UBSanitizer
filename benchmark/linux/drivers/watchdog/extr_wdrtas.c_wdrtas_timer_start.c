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

/* Variables and functions */
 int /*<<< orphan*/  wdrtas_interval ; 
 int /*<<< orphan*/  wdrtas_set_interval (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void wdrtas_timer_start(void)
{
	wdrtas_set_interval(wdrtas_interval);
}