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
struct ipmi_smi_powernv {struct ipmi_smi* intf; } ;
struct ipmi_smi {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int ipmi_powernv_start_processing(void *send_info, struct ipmi_smi *intf)
{
	struct ipmi_smi_powernv *smi = send_info;

	smi->intf = intf;
	return 0;
}