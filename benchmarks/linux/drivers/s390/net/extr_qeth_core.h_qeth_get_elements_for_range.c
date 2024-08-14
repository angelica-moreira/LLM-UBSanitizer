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
typedef  int /*<<< orphan*/  addr_t ;

/* Variables and functions */
 int PFN_DOWN (int /*<<< orphan*/ ) ; 
 int PFN_UP (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int qeth_get_elements_for_range(addr_t start, addr_t end)
{
	return PFN_UP(end) - PFN_DOWN(start);
}