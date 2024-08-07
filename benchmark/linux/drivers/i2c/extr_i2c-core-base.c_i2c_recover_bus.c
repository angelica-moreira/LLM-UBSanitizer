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
struct i2c_adapter {TYPE_1__* bus_recovery_info; int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int (* recover_bus ) (struct i2c_adapter*) ;} ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int stub1 (struct i2c_adapter*) ; 

int i2c_recover_bus(struct i2c_adapter *adap)
{
	if (!adap->bus_recovery_info)
		return -EOPNOTSUPP;

	dev_dbg(&adap->dev, "Trying i2c bus recovery\n");
	return adap->bus_recovery_info->recover_bus(adap);
}