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

/* Variables and functions */
 int HZ ; 
 int cfag12864b_rate ; 
 int /*<<< orphan*/  cfag12864b_work ; 
 int /*<<< orphan*/  cfag12864b_workqueue ; 
 int /*<<< orphan*/  queue_delayed_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void cfag12864b_queue(void)
{
	queue_delayed_work(cfag12864b_workqueue, &cfag12864b_work,
		HZ / cfag12864b_rate);
}