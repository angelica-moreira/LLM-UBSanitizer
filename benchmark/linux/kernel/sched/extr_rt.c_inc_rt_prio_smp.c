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
struct rt_rq {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline
void inc_rt_prio_smp(struct rt_rq *rt_rq, int prio, int prev_prio) {}