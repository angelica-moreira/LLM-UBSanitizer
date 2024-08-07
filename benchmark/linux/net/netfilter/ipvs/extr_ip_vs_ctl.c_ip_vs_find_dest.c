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
typedef  union nf_inet_addr {int dummy; } nf_inet_addr ;
struct netns_ipvs {int dummy; } ;
struct ip_vs_service {int dummy; } ;
struct ip_vs_dest {int dummy; } ;
typedef  int __u32 ;
typedef  int /*<<< orphan*/  __u16 ;
typedef  int __be16 ;

/* Variables and functions */
 int IP_VS_CONN_F_FWD_MASK ; 
 int IP_VS_CONN_F_MASQ ; 
 struct ip_vs_dest* ip_vs_lookup_dest (struct ip_vs_service*,int,union nf_inet_addr const*,int) ; 
 struct ip_vs_service* ip_vs_service_find (struct netns_ipvs*,int,int,int /*<<< orphan*/ ,union nf_inet_addr const*,int) ; 

struct ip_vs_dest *ip_vs_find_dest(struct netns_ipvs *ipvs, int svc_af, int dest_af,
				   const union nf_inet_addr *daddr,
				   __be16 dport,
				   const union nf_inet_addr *vaddr,
				   __be16 vport, __u16 protocol, __u32 fwmark,
				   __u32 flags)
{
	struct ip_vs_dest *dest;
	struct ip_vs_service *svc;
	__be16 port = dport;

	svc = ip_vs_service_find(ipvs, svc_af, fwmark, protocol, vaddr, vport);
	if (!svc)
		return NULL;
	if (fwmark && (flags & IP_VS_CONN_F_FWD_MASK) != IP_VS_CONN_F_MASQ)
		port = 0;
	dest = ip_vs_lookup_dest(svc, dest_af, daddr, port);
	if (!dest)
		dest = ip_vs_lookup_dest(svc, dest_af, daddr, port ^ dport);
	return dest;
}