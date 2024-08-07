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
typedef  int /*<<< orphan*/  xfrm_address_t ;
typedef  unsigned short u32 ;

/* Variables and functions */
#define  AF_INET 129 
#define  AF_INET6 128 
 unsigned int __xfrm4_daddr_saddr_hash (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 unsigned int __xfrm6_daddr_saddr_hash (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static inline unsigned int __xfrm_dst_hash(const xfrm_address_t *daddr,
					   const xfrm_address_t *saddr,
					   u32 reqid, unsigned short family,
					   unsigned int hmask)
{
	unsigned int h = family ^ reqid;
	switch (family) {
	case AF_INET:
		h ^= __xfrm4_daddr_saddr_hash(daddr, saddr);
		break;
	case AF_INET6:
		h ^= __xfrm6_daddr_saddr_hash(daddr, saddr);
		break;
	}
	return (h ^ (h >> 16)) & hmask;
}