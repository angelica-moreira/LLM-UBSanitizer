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
typedef  int /*<<< orphan*/  u32 ;
struct be_mcc_wrb {int /*<<< orphan*/  member_0; } ;
struct TYPE_2__ {int /*<<< orphan*/  domain; } ;
struct be_cmd_req_if_destroy {int /*<<< orphan*/  interface_id; TYPE_1__ hdr; } ;
struct be_adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_SUBSYSTEM_COMMON ; 
 int /*<<< orphan*/  OPCODE_COMMON_NTWK_INTERFACE_DESTROY ; 
 int be_cmd_notify_wait (struct be_adapter*,struct be_mcc_wrb*) ; 
 int /*<<< orphan*/  be_wrb_cmd_hdr_prepare (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,struct be_mcc_wrb*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 struct be_cmd_req_if_destroy* embedded_payload (struct be_mcc_wrb*) ; 

int be_cmd_if_destroy(struct be_adapter *adapter, int interface_id, u32 domain)
{
	struct be_mcc_wrb wrb = {0};
	struct be_cmd_req_if_destroy *req;
	int status;

	if (interface_id == -1)
		return 0;

	req = embedded_payload(&wrb);

	be_wrb_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_COMMON,
			       OPCODE_COMMON_NTWK_INTERFACE_DESTROY,
			       sizeof(*req), &wrb, NULL);
	req->hdr.domain = domain;
	req->interface_id = cpu_to_le32(interface_id);

	status = be_cmd_notify_wait(adapter, &wrb);
	return status;
}