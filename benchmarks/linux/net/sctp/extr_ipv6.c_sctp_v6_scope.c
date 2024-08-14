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
struct TYPE_2__ {int /*<<< orphan*/  sin6_addr; } ;
union sctp_addr {TYPE_1__ v6; } ;
typedef  enum sctp_scope { ____Placeholder_sctp_scope } sctp_scope ;

/* Variables and functions */
#define  IFA_HOST 130 
#define  IFA_LINK 129 
#define  IFA_SITE 128 
 int SCTP_SCOPE_GLOBAL ; 
 int SCTP_SCOPE_LINK ; 
 int SCTP_SCOPE_LOOPBACK ; 
 int SCTP_SCOPE_PRIVATE ; 
 int ipv6_addr_scope (int /*<<< orphan*/ *) ; 

__attribute__((used)) static enum sctp_scope sctp_v6_scope(union sctp_addr *addr)
{
	enum sctp_scope retval;
	int v6scope;

	/* The IPv6 scope is really a set of bit fields.
	 * See IFA_* in <net/if_inet6.h>.  Map to a generic SCTP scope.
	 */

	v6scope = ipv6_addr_scope(&addr->v6.sin6_addr);
	switch (v6scope) {
	case IFA_HOST:
		retval = SCTP_SCOPE_LOOPBACK;
		break;
	case IFA_LINK:
		retval = SCTP_SCOPE_LINK;
		break;
	case IFA_SITE:
		retval = SCTP_SCOPE_PRIVATE;
		break;
	default:
		retval = SCTP_SCOPE_GLOBAL;
		break;
	}

	return retval;
}