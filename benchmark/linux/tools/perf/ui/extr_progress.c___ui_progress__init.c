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
struct ui_progress {int next; int step; int total; char const* title; int size; scalar_t__ curr; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* init ) (struct ui_progress*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct ui_progress*) ; 
 TYPE_1__* ui_progress__ops ; 

void __ui_progress__init(struct ui_progress *p, u64 total,
			 const char *title, bool size)
{
	p->curr = 0;
	p->next = p->step = total / 16 ?: 1;
	p->total = total;
	p->title = title;
	p->size  = size;

	if (ui_progress__ops->init)
		ui_progress__ops->init(p);
}