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
struct prefixmsg {int dummy; } ;
struct prefix_cacheinfo {int dummy; } ;
struct in6_addr {int dummy; } ;

/* Variables and functions */
 size_t NLMSG_ALIGN (int) ; 
 size_t nla_total_size (int) ; 

__attribute__((used)) static inline size_t inet6_prefix_nlmsg_size(void)
{
	return NLMSG_ALIGN(sizeof(struct prefixmsg))
	       + nla_total_size(sizeof(struct in6_addr))
	       + nla_total_size(sizeof(struct prefix_cacheinfo));
}