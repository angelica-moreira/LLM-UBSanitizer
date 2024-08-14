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
struct inet6_dev {int /*<<< orphan*/  mc_ifc_timer; scalar_t__ mc_ifc_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  __in6_dev_put (struct inet6_dev*) ; 
 scalar_t__ del_timer (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mld_ifc_stop_timer(struct inet6_dev *idev)
{
	idev->mc_ifc_count = 0;
	if (del_timer(&idev->mc_ifc_timer))
		__in6_dev_put(idev);
}