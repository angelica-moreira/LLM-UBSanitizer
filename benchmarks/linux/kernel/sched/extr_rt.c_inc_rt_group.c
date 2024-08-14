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
struct sched_rt_entity {int dummy; } ;
struct rt_rq {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  def_rt_bandwidth ; 
 int /*<<< orphan*/  start_rt_bandwidth (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
inc_rt_group(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
	start_rt_bandwidth(&def_rt_bandwidth);
}