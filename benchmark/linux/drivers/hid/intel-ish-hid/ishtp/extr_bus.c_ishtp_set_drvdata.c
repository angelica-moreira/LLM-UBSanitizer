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
struct ishtp_cl_device {void* driver_data; } ;

/* Variables and functions */

void ishtp_set_drvdata(struct ishtp_cl_device *cl_device, void *data)
{
	cl_device->driver_data = data;
}