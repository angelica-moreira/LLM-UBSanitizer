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
typedef  int u64 ;
struct TYPE_2__ {unsigned long long config; } ;
struct event {TYPE_1__ attr; } ;

/* Variables and functions */

void event_bhrb_init(struct event *e, unsigned ifm)
{
	e->attr.config |= (1ull << 62) | ((u64)ifm << 60);
}