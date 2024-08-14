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
struct fpga_manager {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 struct fpga_manager* ERR_PTR (int /*<<< orphan*/ ) ; 
 struct fpga_manager* __fpga_mgr_get (struct device*) ; 
 struct device* class_find_device (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fpga_mgr_class ; 
 int /*<<< orphan*/  fpga_mgr_dev_match ; 

struct fpga_manager *fpga_mgr_get(struct device *dev)
{
	struct device *mgr_dev = class_find_device(fpga_mgr_class, NULL, dev,
						   fpga_mgr_dev_match);
	if (!mgr_dev)
		return ERR_PTR(-ENODEV);

	return __fpga_mgr_get(mgr_dev);
}