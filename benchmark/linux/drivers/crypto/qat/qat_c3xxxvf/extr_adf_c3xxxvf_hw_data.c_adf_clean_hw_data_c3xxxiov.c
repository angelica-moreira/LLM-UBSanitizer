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
struct adf_hw_device_data {TYPE_1__* dev_class; } ;
struct TYPE_2__ {int /*<<< orphan*/  instances; } ;

/* Variables and functions */
 int /*<<< orphan*/  adf_devmgr_update_class_index (struct adf_hw_device_data*) ; 

void adf_clean_hw_data_c3xxxiov(struct adf_hw_device_data *hw_data)
{
	hw_data->dev_class->instances--;
	adf_devmgr_update_class_index(hw_data);
}