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
struct device {int dummy; } ;
typedef  void devfreq_event_dev ;

/* Variables and functions */
 scalar_t__ WARN_ON (int) ; 

__attribute__((used)) static int devm_devfreq_event_match(struct device *dev, void *res, void *data)
{
	struct devfreq_event_dev **r = res;

	if (WARN_ON(!r || !*r))
		return 0;

	return *r == data;
}