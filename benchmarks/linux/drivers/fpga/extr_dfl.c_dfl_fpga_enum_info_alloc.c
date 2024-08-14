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
struct dfl_fpga_enum_info {int /*<<< orphan*/  dfls; struct device* dev; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 struct dfl_fpga_enum_info* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_device (struct device*) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 

struct dfl_fpga_enum_info *dfl_fpga_enum_info_alloc(struct device *dev)
{
	struct dfl_fpga_enum_info *info;

	get_device(dev);

	info = devm_kzalloc(dev, sizeof(*info), GFP_KERNEL);
	if (!info) {
		put_device(dev);
		return NULL;
	}

	info->dev = dev;
	INIT_LIST_HEAD(&info->dfls);

	return info;
}