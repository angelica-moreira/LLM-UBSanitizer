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
struct hash_mac4_elem {int /*<<< orphan*/  ether; } ;

/* Variables and functions */
 int ether_addr_equal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool
hash_mac4_data_equal(const struct hash_mac4_elem *e1,
		     const struct hash_mac4_elem *e2,
		     u32 *multi)
{
	return ether_addr_equal(e1->ether, e2->ether);
}