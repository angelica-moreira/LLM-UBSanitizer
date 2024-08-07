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
struct sch56xx_watchdog_data {int /*<<< orphan*/  wddev; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct sch56xx_watchdog_data*) ; 
 int /*<<< orphan*/  watchdog_unregister_device (int /*<<< orphan*/ *) ; 

void sch56xx_watchdog_unregister(struct sch56xx_watchdog_data *data)
{
	watchdog_unregister_device(&data->wddev);
	kfree(data);
}