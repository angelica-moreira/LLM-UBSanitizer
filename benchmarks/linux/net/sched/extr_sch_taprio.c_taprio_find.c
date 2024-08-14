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
struct Qdisc {int dummy; } ;

/* Variables and functions */
 unsigned int TC_H_MIN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  taprio_queue_get (struct Qdisc*,unsigned int) ; 

__attribute__((used)) static unsigned long taprio_find(struct Qdisc *sch, u32 classid)
{
	unsigned int ntx = TC_H_MIN(classid);

	if (!taprio_queue_get(sch, ntx))
		return 0;
	return ntx;
}