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
struct hfi1_devdata {int dummy; } ;

/* Variables and functions */
 int disable_data_vls (struct hfi1_devdata*) ; 
 int /*<<< orphan*/  drain_data_vls (struct hfi1_devdata*) ; 

int stop_drain_data_vls(struct hfi1_devdata *dd)
{
	int ret;

	ret = disable_data_vls(dd);
	if (ret == 0)
		drain_data_vls(dd);

	return ret;
}