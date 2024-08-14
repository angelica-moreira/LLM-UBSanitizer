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
typedef  scalar_t__ u64 ;
struct timer_list {int dummy; } ;
struct qib_devdata {scalar_t__ z_int_counter; int /*<<< orphan*/  intrchk_timer; TYPE_1__* pcidev; int /*<<< orphan*/  (* f_intr_fallback ) (struct qib_devdata*) ;} ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int HZ ; 
 struct qib_devdata* dd ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct qib_devdata* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  intrchk_timer ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ qib_int_counter (struct qib_devdata*) ; 
 int /*<<< orphan*/  stub1 (struct qib_devdata*) ; 

__attribute__((used)) static void verify_interrupt(struct timer_list *t)
{
	struct qib_devdata *dd = from_timer(dd, t, intrchk_timer);
	u64 int_counter;

	if (!dd)
		return; /* being torn down */

	/*
	 * If we don't have a lid or any interrupts, let the user know and
	 * don't bother checking again.
	 */
	int_counter = qib_int_counter(dd) - dd->z_int_counter;
	if (int_counter == 0) {
		if (!dd->f_intr_fallback(dd))
			dev_err(&dd->pcidev->dev,
				"No interrupts detected, not usable.\n");
		else /* re-arm the timer to see if fallback works */
			mod_timer(&dd->intrchk_timer, jiffies + HZ/2);
	}
}