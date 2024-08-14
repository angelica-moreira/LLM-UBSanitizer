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
struct legacy_cpu_model_info {scalar_t__ family; char const** model_names; } ;
struct cpuinfo_x86 {int x86_model; scalar_t__ x86; } ;
struct TYPE_2__ {struct legacy_cpu_model_info* legacy_models; } ;

/* Variables and functions */
 TYPE_1__* this_cpu ; 

__attribute__((used)) static const char *table_lookup_model(struct cpuinfo_x86 *c)
{
#ifdef CONFIG_X86_32
	const struct legacy_cpu_model_info *info;

	if (c->x86_model >= 16)
		return NULL;	/* Range check */

	if (!this_cpu)
		return NULL;

	info = this_cpu->legacy_models;

	while (info->family) {
		if (info->family == c->x86)
			return info->model_names[c->x86_model];
		info++;
	}
#endif
	return NULL;		/* Not found */
}