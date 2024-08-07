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
struct request_queue {TYPE_1__* backing_dev_info; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {int ra_pages; } ;

/* Variables and functions */
 int PAGE_SHIFT ; 
 int /*<<< orphan*/  queue_var_show (unsigned long,char*) ; 

__attribute__((used)) static ssize_t queue_ra_show(struct request_queue *q, char *page)
{
	unsigned long ra_kb = q->backing_dev_info->ra_pages <<
					(PAGE_SHIFT - 10);

	return queue_var_show(ra_kb, (page));
}