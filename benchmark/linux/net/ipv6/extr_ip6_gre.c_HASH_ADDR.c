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
typedef  int /*<<< orphan*/  u32 ;
struct in6_addr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IP6_GRE_HASH_SIZE_SHIFT ; 
 int /*<<< orphan*/  hash_32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipv6_addr_hash (struct in6_addr const*) ; 

__attribute__((used)) static u32 HASH_ADDR(const struct in6_addr *addr)
{
	u32 hash = ipv6_addr_hash(addr);

	return hash_32(hash, IP6_GRE_HASH_SIZE_SHIFT);
}