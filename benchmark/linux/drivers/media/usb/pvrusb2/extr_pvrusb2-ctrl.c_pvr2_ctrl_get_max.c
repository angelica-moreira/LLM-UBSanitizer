#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct pvr2_ctrl {TYPE_3__* hdw; TYPE_4__* info; } ;
struct TYPE_5__ {int max_value; } ;
struct TYPE_6__ {TYPE_1__ type_int; } ;
struct TYPE_8__ {scalar_t__ type; TYPE_2__ def; int /*<<< orphan*/  (* get_max_value ) (struct pvr2_ctrl*,int*) ;} ;
struct TYPE_7__ {int /*<<< orphan*/  big_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOCK_GIVE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOCK_TAKE (int /*<<< orphan*/ ) ; 
 scalar_t__ pvr2_ctl_int ; 
 int /*<<< orphan*/  stub1 (struct pvr2_ctrl*,int*) ; 

int pvr2_ctrl_get_max(struct pvr2_ctrl *cptr)
{
	int ret = 0;
	if (!cptr) return 0;
	LOCK_TAKE(cptr->hdw->big_lock); do {
		if (cptr->info->get_max_value) {
			cptr->info->get_max_value(cptr,&ret);
		} else if (cptr->info->type == pvr2_ctl_int) {
			ret = cptr->info->def.type_int.max_value;
		}
	} while(0); LOCK_GIVE(cptr->hdw->big_lock);
	return ret;
}