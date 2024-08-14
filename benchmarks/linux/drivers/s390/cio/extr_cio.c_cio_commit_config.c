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
struct subchannel {int /*<<< orphan*/  schid; int /*<<< orphan*/  schib; } ;
struct schib {int dummy; } ;
struct irb {int dummy; } ;
typedef  int /*<<< orphan*/  schib ;

/* Variables and functions */
 int EAGAIN ; 
 int EBUSY ; 
 int ENODEV ; 
 int /*<<< orphan*/  cio_apply_config (struct subchannel*,struct schib*) ; 
 int /*<<< orphan*/  cio_check_config (struct subchannel*,struct schib*) ; 
 int /*<<< orphan*/  css_sch_is_valid (struct schib*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,struct schib*,int) ; 
 int msch (int /*<<< orphan*/ ,struct schib*) ; 
 scalar_t__ stsch (int /*<<< orphan*/ ,struct schib*) ; 
 int /*<<< orphan*/  tsch (int /*<<< orphan*/ ,struct irb*) ; 
 int /*<<< orphan*/  udelay (int) ; 

int cio_commit_config(struct subchannel *sch)
{
	int ccode, retry, ret = 0;
	struct schib schib;
	struct irb irb;

	if (stsch(sch->schid, &schib) || !css_sch_is_valid(&schib))
		return -ENODEV;

	for (retry = 0; retry < 5; retry++) {
		/* copy desired changes to local schib */
		cio_apply_config(sch, &schib);
		ccode = msch(sch->schid, &schib);
		if (ccode < 0) /* -EIO if msch gets a program check. */
			return ccode;
		switch (ccode) {
		case 0: /* successful */
			if (stsch(sch->schid, &schib) ||
			    !css_sch_is_valid(&schib))
				return -ENODEV;
			if (cio_check_config(sch, &schib)) {
				/* commit changes from local schib */
				memcpy(&sch->schib, &schib, sizeof(schib));
				return 0;
			}
			ret = -EAGAIN;
			break;
		case 1: /* status pending */
			ret = -EBUSY;
			if (tsch(sch->schid, &irb))
				return ret;
			break;
		case 2: /* busy */
			udelay(100); /* allow for recovery */
			ret = -EBUSY;
			break;
		case 3: /* not operational */
			return -ENODEV;
		}
	}
	return ret;
}