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
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long* krealloc (unsigned long*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int add_config(struct device *dev, unsigned long **configs,
		      unsigned *num_configs, unsigned long config)
{
	unsigned old_num = *num_configs;
	unsigned new_num = old_num + 1;
	unsigned long *new_configs;

	new_configs = krealloc(*configs, sizeof(*new_configs) * new_num,
			       GFP_KERNEL);
	if (!new_configs)
		return -ENOMEM;

	new_configs[old_num] = config;

	*configs = new_configs;
	*num_configs = new_num;

	return 0;
}