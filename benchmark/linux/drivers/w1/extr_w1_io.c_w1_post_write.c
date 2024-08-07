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
struct w1_master {scalar_t__ pullup_duration; TYPE_1__* bus_master; scalar_t__ enable_pullup; } ;
struct TYPE_2__ {int /*<<< orphan*/  data; int /*<<< orphan*/  (* set_pullup ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  msleep (scalar_t__) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void w1_post_write(struct w1_master *dev)
{
	if (dev->pullup_duration) {
		if (dev->enable_pullup && dev->bus_master->set_pullup)
			dev->bus_master->set_pullup(dev->bus_master->data, 0);
		else
			msleep(dev->pullup_duration);
		dev->pullup_duration = 0;
	}
}