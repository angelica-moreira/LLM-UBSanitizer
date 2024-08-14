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
struct t3cdev {int /*<<< orphan*/ * neigh_update; int /*<<< orphan*/ * recv; } ;
struct adapter {struct t3cdev tdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  unregister_tdev (struct t3cdev*) ; 

void cxgb3_adapter_unofld(struct adapter *adapter)
{
	struct t3cdev *tdev = &adapter->tdev;

	tdev->recv = NULL;
	tdev->neigh_update = NULL;

	unregister_tdev(tdev);
}