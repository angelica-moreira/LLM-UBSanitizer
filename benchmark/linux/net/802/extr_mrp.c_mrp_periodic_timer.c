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
struct mrp_applicant {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  MRP_EVENT_PERIODIC ; 
 struct mrp_applicant* app ; 
 struct mrp_applicant* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrp_mad_event (struct mrp_applicant*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrp_pdu_queue (struct mrp_applicant*) ; 
 int /*<<< orphan*/  mrp_periodic_timer_arm (struct mrp_applicant*) ; 
 int /*<<< orphan*/  periodic_timer ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mrp_periodic_timer(struct timer_list *t)
{
	struct mrp_applicant *app = from_timer(app, t, periodic_timer);

	spin_lock(&app->lock);
	mrp_mad_event(app, MRP_EVENT_PERIODIC);
	mrp_pdu_queue(app);
	spin_unlock(&app->lock);

	mrp_periodic_timer_arm(app);
}