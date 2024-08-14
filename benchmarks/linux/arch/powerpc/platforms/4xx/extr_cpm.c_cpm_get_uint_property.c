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

/* Variables and functions */
 unsigned int* of_get_property (struct device_node*,char const*,int*) ; 

__attribute__((used)) static int cpm_get_uint_property(struct device_node *np,
				 const char *name)
{
	int len;
	const unsigned int *prop = of_get_property(np, name, &len);

	if (prop == NULL || len < sizeof(u32))
		return 0;

	return *prop;
}