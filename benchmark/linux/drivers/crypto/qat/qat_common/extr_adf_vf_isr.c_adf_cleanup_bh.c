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
struct adf_etr_data {TYPE_1__* banks; } ;
struct adf_accel_dev {struct adf_etr_data* transport; } ;
struct TYPE_2__ {int /*<<< orphan*/  resp_handler; } ;

/* Variables and functions */
 int /*<<< orphan*/  tasklet_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tasklet_kill (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void adf_cleanup_bh(struct adf_accel_dev *accel_dev)
{
	struct adf_etr_data *priv_data = accel_dev->transport;

	tasklet_disable(&priv_data->banks[0].resp_handler);
	tasklet_kill(&priv_data->banks[0].resp_handler);
}