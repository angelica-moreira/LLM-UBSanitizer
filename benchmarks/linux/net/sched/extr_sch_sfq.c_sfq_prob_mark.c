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
struct sfq_sched_data {int flags; } ;

/* Variables and functions */
 int TC_RED_ECN ; 

__attribute__((used)) static int sfq_prob_mark(const struct sfq_sched_data *q)
{
	return q->flags & TC_RED_ECN;
}