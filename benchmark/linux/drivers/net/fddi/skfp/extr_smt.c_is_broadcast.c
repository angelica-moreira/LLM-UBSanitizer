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
typedef  int u_short ;
struct fddi_addr {int /*<<< orphan*/ * a; } ;

/* Variables and functions */

__attribute__((used)) static inline int is_broadcast(const struct fddi_addr *addr)
{
	return *(u_short *)(&addr->a[0]) == 0xffff &&
	       *(u_short *)(&addr->a[2]) == 0xffff &&
	       *(u_short *)(&addr->a[4]) == 0xffff;
}