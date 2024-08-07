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
struct ti_adpll_data {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ADPLL_MAX_RETRIES ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ ti_adpll_is_locked (struct ti_adpll_data*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int ti_adpll_wait_lock(struct ti_adpll_data *d)
{
	int retries = ADPLL_MAX_RETRIES;

	do {
		if (ti_adpll_is_locked(d))
			return 0;
		usleep_range(200, 300);
	} while (retries--);

	dev_err(d->dev, "pll failed to lock\n");
	return -ETIMEDOUT;
}