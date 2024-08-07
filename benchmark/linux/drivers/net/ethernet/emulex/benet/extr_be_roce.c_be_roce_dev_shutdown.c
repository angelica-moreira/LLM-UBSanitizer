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
struct be_adapter {scalar_t__ ocrdma_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* state_change_handler ) (scalar_t__,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BE_DEV_SHUTDOWN ; 
 int /*<<< orphan*/  be_adapter_list_lock ; 
 scalar_t__ be_roce_supported (struct be_adapter*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_1__* ocrdma_drv ; 
 int /*<<< orphan*/  stub1 (scalar_t__,int /*<<< orphan*/ ) ; 

void be_roce_dev_shutdown(struct be_adapter *adapter)
{
	if (be_roce_supported(adapter)) {
		mutex_lock(&be_adapter_list_lock);
		if (ocrdma_drv && adapter->ocrdma_dev &&
		    ocrdma_drv->state_change_handler)
			ocrdma_drv->state_change_handler(adapter->ocrdma_dev,
							 BE_DEV_SHUTDOWN);
		mutex_unlock(&be_adapter_list_lock);
	}
}