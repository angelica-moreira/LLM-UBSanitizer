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
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sch_adapter ; 
 scalar_t__ sch_smba ; 

__attribute__((used)) static int smbus_sch_remove(struct platform_device *pdev)
{
	if (sch_smba) {
		i2c_del_adapter(&sch_adapter);
		sch_smba = 0;
	}

	return 0;
}