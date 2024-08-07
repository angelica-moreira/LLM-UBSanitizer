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
struct realtek_smi {int num_ports; TYPE_1__* ops; } ;
struct TYPE_2__ {int (* get_mc_index ) (struct realtek_smi*,int,int*) ;} ;

/* Variables and functions */
 int stub1 (struct realtek_smi*,int,int*) ; 

int rtl8366_mc_is_used(struct realtek_smi *smi, int mc_index, int *used)
{
	int ret;
	int i;

	*used = 0;
	for (i = 0; i < smi->num_ports; i++) {
		int index = 0;

		ret = smi->ops->get_mc_index(smi, i, &index);
		if (ret)
			return ret;

		if (mc_index == index) {
			*used = 1;
			break;
		}
	}

	return 0;
}