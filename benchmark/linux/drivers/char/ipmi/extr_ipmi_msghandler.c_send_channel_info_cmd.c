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
struct kernel_ipmi_msg {unsigned char* data; int data_len; int /*<<< orphan*/  cmd; int /*<<< orphan*/  netfn; } ;
struct ipmi_system_interface_addr {scalar_t__ lun; int /*<<< orphan*/  channel; int /*<<< orphan*/  addr_type; } ;
struct ipmi_smi {TYPE_1__* addrinfo; } ;
struct ipmi_addr {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  lun; int /*<<< orphan*/  address; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPMI_BMC_CHANNEL ; 
 int /*<<< orphan*/  IPMI_GET_CHANNEL_INFO_CMD ; 
 int /*<<< orphan*/  IPMI_NETFN_APP_REQUEST ; 
 int /*<<< orphan*/  IPMI_SYSTEM_INTERFACE_ADDR_TYPE ; 
 int i_ipmi_request (int /*<<< orphan*/ *,struct ipmi_smi*,struct ipmi_addr*,int /*<<< orphan*/ ,struct kernel_ipmi_msg*,struct ipmi_smi*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
send_channel_info_cmd(struct ipmi_smi *intf, int chan)
{
	struct kernel_ipmi_msg            msg;
	unsigned char                     data[1];
	struct ipmi_system_interface_addr si;

	si.addr_type = IPMI_SYSTEM_INTERFACE_ADDR_TYPE;
	si.channel = IPMI_BMC_CHANNEL;
	si.lun = 0;

	msg.netfn = IPMI_NETFN_APP_REQUEST;
	msg.cmd = IPMI_GET_CHANNEL_INFO_CMD;
	msg.data = data;
	msg.data_len = 1;
	data[0] = chan;
	return i_ipmi_request(NULL,
			      intf,
			      (struct ipmi_addr *) &si,
			      0,
			      &msg,
			      intf,
			      NULL,
			      NULL,
			      0,
			      intf->addrinfo[0].address,
			      intf->addrinfo[0].lun,
			      -1, 0);
}