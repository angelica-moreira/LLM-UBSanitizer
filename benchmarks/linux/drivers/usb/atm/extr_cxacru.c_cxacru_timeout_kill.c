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
struct timer_list {int dummy; } ;
struct cxacru_timer {int /*<<< orphan*/  urb; } ;

/* Variables and functions */
 struct cxacru_timer* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 struct cxacru_timer* timer ; 
 int /*<<< orphan*/  usb_unlink_urb (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cxacru_timeout_kill(struct timer_list *t)
{
	struct cxacru_timer *timer = from_timer(timer, t, timer);

	usb_unlink_urb(timer->urb);
}