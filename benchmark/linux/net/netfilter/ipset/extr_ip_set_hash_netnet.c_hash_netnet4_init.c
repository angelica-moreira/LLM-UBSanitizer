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
struct hash_netnet4_elem {void** cidr; } ;

/* Variables and functions */
 void* HOST_MASK ; 

__attribute__((used)) static void
hash_netnet4_init(struct hash_netnet4_elem *e)
{
	e->cidr[0] = HOST_MASK;
	e->cidr[1] = HOST_MASK;
}