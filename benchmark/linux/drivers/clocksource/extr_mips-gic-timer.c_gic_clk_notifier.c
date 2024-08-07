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
struct notifier_block {int dummy; } ;
struct clk_notifier_data {scalar_t__ new_rate; } ;

/* Variables and functions */
 int NOTIFY_OK ; 
 unsigned long POST_RATE_CHANGE ; 
 int /*<<< orphan*/  gic_update_frequency ; 
 int /*<<< orphan*/  on_each_cpu (int /*<<< orphan*/ ,void*,int) ; 

__attribute__((used)) static int gic_clk_notifier(struct notifier_block *nb, unsigned long action,
			    void *data)
{
	struct clk_notifier_data *cnd = data;

	if (action == POST_RATE_CHANGE)
		on_each_cpu(gic_update_frequency, (void *)cnd->new_rate, 1);

	return NOTIFY_OK;
}