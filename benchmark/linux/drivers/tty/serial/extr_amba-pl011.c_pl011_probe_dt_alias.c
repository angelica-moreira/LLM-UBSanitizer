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
struct device_node {int dummy; } ;
struct device {struct device_node* of_node; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ ** amba_ports ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int of_alias_get_id (struct device_node*,char*) ; 

__attribute__((used)) static int pl011_probe_dt_alias(int index, struct device *dev)
{
	struct device_node *np;
	static bool seen_dev_with_alias = false;
	static bool seen_dev_without_alias = false;
	int ret = index;

	if (!IS_ENABLED(CONFIG_OF))
		return ret;

	np = dev->of_node;
	if (!np)
		return ret;

	ret = of_alias_get_id(np, "serial");
	if (ret < 0) {
		seen_dev_without_alias = true;
		ret = index;
	} else {
		seen_dev_with_alias = true;
		if (ret >= ARRAY_SIZE(amba_ports) || amba_ports[ret] != NULL) {
			dev_warn(dev, "requested serial port %d  not available.\n", ret);
			ret = index;
		}
	}

	if (seen_dev_with_alias && seen_dev_without_alias)
		dev_warn(dev, "aliased and non-aliased serial devices found in device tree. Serial port enumeration may be unpredictable.\n");

	return ret;
}