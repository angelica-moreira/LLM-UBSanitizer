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
struct platform_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  OPAL_MSG_PRD ; 
 int /*<<< orphan*/  misc_deregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  opal_message_notifier_unregister (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  opal_prd_dev ; 
 int /*<<< orphan*/  opal_prd_event_nb ; 

__attribute__((used)) static int opal_prd_remove(struct platform_device *pdev)
{
	misc_deregister(&opal_prd_dev);
	opal_message_notifier_unregister(OPAL_MSG_PRD, &opal_prd_event_nb);
	return 0;
}