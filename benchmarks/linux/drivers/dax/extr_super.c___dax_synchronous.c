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
struct dax_device {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  DAXDEV_SYNC ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

bool __dax_synchronous(struct dax_device *dax_dev)
{
	return test_bit(DAXDEV_SYNC, &dax_dev->flags);
}