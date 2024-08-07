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
struct cma3000_accl_data {int suspended; int /*<<< orphan*/  mutex; scalar_t__ opened; } ;

/* Variables and functions */
 int /*<<< orphan*/  cma3000_poweroff (struct cma3000_accl_data*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

void cma3000_suspend(struct cma3000_accl_data *data)
{
	mutex_lock(&data->mutex);

	if (!data->suspended && data->opened)
		cma3000_poweroff(data);

	data->suspended = true;

	mutex_unlock(&data->mutex);
}