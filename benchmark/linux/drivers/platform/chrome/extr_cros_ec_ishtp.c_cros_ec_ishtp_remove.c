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
struct ishtp_cl_device {int dummy; } ;
struct ishtp_cl_data {int /*<<< orphan*/  work_ec_evt; int /*<<< orphan*/  work_ishtp_reset; } ;
struct ishtp_cl {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cancel_work_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cros_ish_deinit (struct ishtp_cl*) ; 
 struct ishtp_cl_data* ishtp_get_client_data (struct ishtp_cl*) ; 
 struct ishtp_cl* ishtp_get_drvdata (struct ishtp_cl_device*) ; 
 int /*<<< orphan*/  ishtp_put_device (struct ishtp_cl_device*) ; 

__attribute__((used)) static int cros_ec_ishtp_remove(struct ishtp_cl_device *cl_device)
{
	struct ishtp_cl	*cros_ish_cl = ishtp_get_drvdata(cl_device);
	struct ishtp_cl_data *client_data = ishtp_get_client_data(cros_ish_cl);

	cancel_work_sync(&client_data->work_ishtp_reset);
	cancel_work_sync(&client_data->work_ec_evt);
	cros_ish_deinit(cros_ish_cl);
	ishtp_put_device(cl_device);

	return 0;
}