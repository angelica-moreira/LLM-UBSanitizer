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
struct tipc_link {scalar_t__ silent_intv_cnt; scalar_t__ abort_limit; } ;

/* Variables and functions */

bool tipc_link_too_silent(struct tipc_link *l)
{
	return (l->silent_intv_cnt + 2 > l->abort_limit);
}