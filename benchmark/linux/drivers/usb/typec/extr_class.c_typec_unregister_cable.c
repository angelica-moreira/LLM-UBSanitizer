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
struct typec_cable {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR_OR_NULL (struct typec_cable*) ; 
 int /*<<< orphan*/  device_unregister (int /*<<< orphan*/ *) ; 

void typec_unregister_cable(struct typec_cable *cable)
{
	if (!IS_ERR_OR_NULL(cable))
		device_unregister(&cable->dev);
}