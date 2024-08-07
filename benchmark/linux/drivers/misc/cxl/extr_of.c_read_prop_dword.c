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
typedef  int /*<<< orphan*/  u32 ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  be32_to_cpu (int /*<<< orphan*/  const) ; 
 scalar_t__ cxl_verbose ; 
 int /*<<< orphan*/ * of_get_property (struct device_node const*,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static const __be32 *read_prop_dword(const struct device_node *np,
				const char *prop_name, u32 *val)
{
	const __be32 *prop;

	prop = of_get_property(np, prop_name, NULL);
	if (prop)
		*val = be32_to_cpu(prop[0]);
	if (cxl_verbose && prop)
		pr_info("%s: %#x (%u)\n", prop_name, *val, *val);
	return prop;
}