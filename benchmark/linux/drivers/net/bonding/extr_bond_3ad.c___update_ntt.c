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
struct port {scalar_t__ actor_port_number; scalar_t__ actor_port_priority; scalar_t__ actor_system_priority; scalar_t__ actor_oper_port_key; int actor_oper_port_state; int ntt; int /*<<< orphan*/  actor_system; } ;
struct lacpdu {int partner_state; int /*<<< orphan*/  partner_key; int /*<<< orphan*/  partner_system_priority; int /*<<< orphan*/  partner_system; int /*<<< orphan*/  partner_port_priority; int /*<<< orphan*/  partner_port; } ;

/* Variables and functions */
 int AD_STATE_AGGREGATION ; 
 int AD_STATE_LACP_ACTIVITY ; 
 int AD_STATE_LACP_TIMEOUT ; 
 int AD_STATE_SYNCHRONIZATION ; 
 int /*<<< orphan*/  MAC_ADDRESS_EQUAL (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ ntohs (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void __update_ntt(struct lacpdu *lacpdu, struct port *port)
{
	/* validate lacpdu and port */
	if (lacpdu && port) {
		/* check if any parameter is different then
		 * update the port->ntt.
		 */
		if ((ntohs(lacpdu->partner_port) != port->actor_port_number) ||
		    (ntohs(lacpdu->partner_port_priority) != port->actor_port_priority) ||
		    !MAC_ADDRESS_EQUAL(&(lacpdu->partner_system), &(port->actor_system)) ||
		    (ntohs(lacpdu->partner_system_priority) != port->actor_system_priority) ||
		    (ntohs(lacpdu->partner_key) != port->actor_oper_port_key) ||
		    ((lacpdu->partner_state & AD_STATE_LACP_ACTIVITY) != (port->actor_oper_port_state & AD_STATE_LACP_ACTIVITY)) ||
		    ((lacpdu->partner_state & AD_STATE_LACP_TIMEOUT) != (port->actor_oper_port_state & AD_STATE_LACP_TIMEOUT)) ||
		    ((lacpdu->partner_state & AD_STATE_SYNCHRONIZATION) != (port->actor_oper_port_state & AD_STATE_SYNCHRONIZATION)) ||
		    ((lacpdu->partner_state & AD_STATE_AGGREGATION) != (port->actor_oper_port_state & AD_STATE_AGGREGATION))
		   ) {
			port->ntt = true;
		}
	}
}