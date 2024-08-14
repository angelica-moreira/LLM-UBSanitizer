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
struct qfq_class {int /*<<< orphan*/  filter_cnt; } ;
struct Qdisc {int dummy; } ;

/* Variables and functions */
 struct qfq_class* qfq_find_class (struct Qdisc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned long qfq_bind_tcf(struct Qdisc *sch, unsigned long parent,
				  u32 classid)
{
	struct qfq_class *cl = qfq_find_class(sch, classid);

	if (cl != NULL)
		cl->filter_cnt++;

	return (unsigned long)cl;
}