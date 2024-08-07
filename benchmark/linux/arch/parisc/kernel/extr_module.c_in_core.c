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
struct TYPE_2__ {void* base; int size; } ;
struct module {TYPE_1__ core_layout; } ;

/* Variables and functions */

__attribute__((used)) static inline int in_core(struct module *me, void *loc)
{
	return (loc >= me->core_layout.base &&
		loc <= (me->core_layout.base + me->core_layout.size));
}