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
struct xt_mtchk_param {struct ebt_entry* entryinfo; struct ebt_ip_info* matchinfo; } ;
struct ebt_ip_info {int bitmask; int invflags; scalar_t__ protocol; scalar_t__* dport; scalar_t__* sport; scalar_t__* icmp_type; scalar_t__* icmp_code; scalar_t__* igmp_type; } ;
struct ebt_entry {scalar_t__ ethproto; int invflags; } ;

/* Variables and functions */
 int EBT_IPROTO ; 
 int EBT_IP_DPORT ; 
 int EBT_IP_ICMP ; 
 int EBT_IP_IGMP ; 
 int EBT_IP_MASK ; 
 int EBT_IP_PROTO ; 
 int EBT_IP_SPORT ; 
 int EINVAL ; 
 int /*<<< orphan*/  ETH_P_IP ; 
 scalar_t__ IPPROTO_DCCP ; 
 scalar_t__ IPPROTO_ICMP ; 
 scalar_t__ IPPROTO_IGMP ; 
 scalar_t__ IPPROTO_SCTP ; 
 scalar_t__ IPPROTO_TCP ; 
 scalar_t__ IPPROTO_UDP ; 
 scalar_t__ IPPROTO_UDPLITE ; 
 scalar_t__ htons (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ebt_ip_mt_check(const struct xt_mtchk_param *par)
{
	const struct ebt_ip_info *info = par->matchinfo;
	const struct ebt_entry *e = par->entryinfo;

	if (e->ethproto != htons(ETH_P_IP) ||
	   e->invflags & EBT_IPROTO)
		return -EINVAL;
	if (info->bitmask & ~EBT_IP_MASK || info->invflags & ~EBT_IP_MASK)
		return -EINVAL;
	if (info->bitmask & (EBT_IP_DPORT | EBT_IP_SPORT)) {
		if (info->invflags & EBT_IP_PROTO)
			return -EINVAL;
		if (info->protocol != IPPROTO_TCP &&
		    info->protocol != IPPROTO_UDP &&
		    info->protocol != IPPROTO_UDPLITE &&
		    info->protocol != IPPROTO_SCTP &&
		    info->protocol != IPPROTO_DCCP)
			 return -EINVAL;
	}
	if (info->bitmask & EBT_IP_DPORT && info->dport[0] > info->dport[1])
		return -EINVAL;
	if (info->bitmask & EBT_IP_SPORT && info->sport[0] > info->sport[1])
		return -EINVAL;
	if (info->bitmask & EBT_IP_ICMP) {
		if ((info->invflags & EBT_IP_PROTO) ||
		    info->protocol != IPPROTO_ICMP)
			return -EINVAL;
		if (info->icmp_type[0] > info->icmp_type[1] ||
		    info->icmp_code[0] > info->icmp_code[1])
			return -EINVAL;
	}
	if (info->bitmask & EBT_IP_IGMP) {
		if ((info->invflags & EBT_IP_PROTO) ||
		    info->protocol != IPPROTO_IGMP)
			return -EINVAL;
		if (info->igmp_type[0] > info->igmp_type[1])
			return -EINVAL;
	}
	return 0;
}