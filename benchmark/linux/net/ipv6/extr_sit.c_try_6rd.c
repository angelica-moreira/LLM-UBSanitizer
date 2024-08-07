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
struct ip_tunnel {int dummy; } ;
struct in6_addr {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  check_6rd (struct ip_tunnel*,struct in6_addr const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline __be32 try_6rd(struct ip_tunnel *tunnel,
			     const struct in6_addr *v6dst)
{
	__be32 dst = 0;
	check_6rd(tunnel, v6dst, &dst);
	return dst;
}