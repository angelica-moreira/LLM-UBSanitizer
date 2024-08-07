#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  parent; } ;
struct subchannel {TYPE_1__ dev; } ;
struct TYPE_4__ {struct subchannel* pseudo_subchannel; } ;

/* Variables and functions */
 TYPE_2__* to_css (int /*<<< orphan*/ ) ; 

int sch_is_pseudo_sch(struct subchannel *sch)
{
	if (!sch->dev.parent)
		return 0;
	return sch == to_css(sch->dev.parent)->pseudo_subchannel;
}