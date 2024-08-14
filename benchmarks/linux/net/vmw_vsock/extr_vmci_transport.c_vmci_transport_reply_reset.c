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
struct vmci_transport_packet {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VMCI_INVALID_HANDLE ; 
 int /*<<< orphan*/  VMCI_TRANSPORT_PACKET_TYPE_RST ; 
 int vmci_transport_reply_control_pkt_fast (struct vmci_transport_packet*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int vmci_transport_reply_reset(struct vmci_transport_packet *pkt)
{
	return vmci_transport_reply_control_pkt_fast(
						pkt,
						VMCI_TRANSPORT_PACKET_TYPE_RST,
						0, 0, NULL,
						VMCI_INVALID_HANDLE);
}