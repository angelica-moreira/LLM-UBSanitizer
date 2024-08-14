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
struct host1x_syncpt {int /*<<< orphan*/  id; int /*<<< orphan*/  host; } ;

/* Variables and functions */
 int /*<<< orphan*/  host1x_hw_syncpt_load (int /*<<< orphan*/ ,struct host1x_syncpt*) ; 
 int /*<<< orphan*/  trace_host1x_syncpt_load_min (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

u32 host1x_syncpt_load(struct host1x_syncpt *sp)
{
	u32 val;

	val = host1x_hw_syncpt_load(sp->host, sp);
	trace_host1x_syncpt_load_min(sp->id, val);

	return val;
}