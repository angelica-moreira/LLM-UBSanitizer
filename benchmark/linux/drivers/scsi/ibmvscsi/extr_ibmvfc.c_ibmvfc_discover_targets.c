#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct ibmvfc_host {int disc_buf_sz; int /*<<< orphan*/  disc_buf_dma; } ;
struct TYPE_6__ {void* len; int /*<<< orphan*/  va; } ;
struct TYPE_5__ {int /*<<< orphan*/  length; void* opcode; void* version; } ;
struct ibmvfc_discover_targets {TYPE_3__ buffer; void* bufflen; TYPE_2__ common; } ;
struct TYPE_4__ {struct ibmvfc_discover_targets discover_targets; } ;
struct ibmvfc_event {TYPE_1__ iu; } ;

/* Variables and functions */
 int IBMVFC_DISC_TARGETS ; 
 int /*<<< orphan*/  IBMVFC_HOST_ACTION_INIT_WAIT ; 
 int /*<<< orphan*/  IBMVFC_LINK_DEAD ; 
 int /*<<< orphan*/  IBMVFC_MAD_FORMAT ; 
 int /*<<< orphan*/  cpu_to_be16 (int) ; 
 void* cpu_to_be32 (int) ; 
 int /*<<< orphan*/  cpu_to_be64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  default_timeout ; 
 int /*<<< orphan*/  ibmvfc_dbg (struct ibmvfc_host*,char*) ; 
 int /*<<< orphan*/  ibmvfc_discover_targets_done ; 
 struct ibmvfc_event* ibmvfc_get_event (struct ibmvfc_host*) ; 
 int /*<<< orphan*/  ibmvfc_init_event (struct ibmvfc_event*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ibmvfc_link_down (struct ibmvfc_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ibmvfc_send_event (struct ibmvfc_event*,struct ibmvfc_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ibmvfc_set_host_action (struct ibmvfc_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct ibmvfc_discover_targets*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void ibmvfc_discover_targets(struct ibmvfc_host *vhost)
{
	struct ibmvfc_discover_targets *mad;
	struct ibmvfc_event *evt = ibmvfc_get_event(vhost);

	ibmvfc_init_event(evt, ibmvfc_discover_targets_done, IBMVFC_MAD_FORMAT);
	mad = &evt->iu.discover_targets;
	memset(mad, 0, sizeof(*mad));
	mad->common.version = cpu_to_be32(1);
	mad->common.opcode = cpu_to_be32(IBMVFC_DISC_TARGETS);
	mad->common.length = cpu_to_be16(sizeof(*mad));
	mad->bufflen = cpu_to_be32(vhost->disc_buf_sz);
	mad->buffer.va = cpu_to_be64(vhost->disc_buf_dma);
	mad->buffer.len = cpu_to_be32(vhost->disc_buf_sz);
	ibmvfc_set_host_action(vhost, IBMVFC_HOST_ACTION_INIT_WAIT);

	if (!ibmvfc_send_event(evt, vhost, default_timeout))
		ibmvfc_dbg(vhost, "Sent discover targets\n");
	else
		ibmvfc_link_down(vhost, IBMVFC_LINK_DEAD);
}