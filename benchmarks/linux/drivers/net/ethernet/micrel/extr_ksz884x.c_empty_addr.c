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
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;

/* Variables and functions */

__attribute__((used)) static int empty_addr(u8 *addr)
{
	u32 *addr1 = (u32 *) addr;
	u16 *addr2 = (u16 *) &addr[4];

	return 0 == *addr1 && 0 == *addr2;
}