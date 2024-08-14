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
struct be_adapter {int /*<<< orphan*/ * ocrdma_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* remove ) (int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 TYPE_1__* ocrdma_drv ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void _be_roce_dev_remove(struct be_adapter *adapter)
{
	if (ocrdma_drv && ocrdma_drv->remove && adapter->ocrdma_dev)
		ocrdma_drv->remove(adapter->ocrdma_dev);
	adapter->ocrdma_dev = NULL;
}