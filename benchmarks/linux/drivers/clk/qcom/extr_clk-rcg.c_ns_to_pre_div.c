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
typedef  int u32 ;
struct pre_div {int pre_div_shift; int /*<<< orphan*/  pre_div_width; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 ns_to_pre_div(struct pre_div *p, u32 ns)
{
	ns >>= p->pre_div_shift;
	ns &= BIT(p->pre_div_width) - 1;
	return ns;
}