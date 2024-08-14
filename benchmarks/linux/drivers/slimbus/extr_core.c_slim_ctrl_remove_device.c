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

/* Variables and functions */
 int /*<<< orphan*/  slim_remove_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_slim_device (struct device*) ; 

__attribute__((used)) static int slim_ctrl_remove_device(struct device *dev, void *null)
{
	slim_remove_device(to_slim_device(dev));
	return 0;
}