#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {unsigned long funcaddr; } ;

/* Variables and functions */
 TYPE_1__ func_desc (unsigned long) ; 

__attribute__((used)) static unsigned long func_addr(unsigned long addr)
{
	return func_desc(addr).funcaddr;
}