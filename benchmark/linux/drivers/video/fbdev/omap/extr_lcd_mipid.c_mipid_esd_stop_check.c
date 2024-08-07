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
struct mipid_device {int /*<<< orphan*/  esd_work; int /*<<< orphan*/ * esd_check; } ;

/* Variables and functions */
 int /*<<< orphan*/  cancel_delayed_work_sync (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mipid_esd_stop_check(struct mipid_device *md)
{
	if (md->esd_check != NULL)
		cancel_delayed_work_sync(&md->esd_work);
}