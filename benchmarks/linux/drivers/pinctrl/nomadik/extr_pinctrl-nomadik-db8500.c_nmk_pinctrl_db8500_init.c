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
struct nmk_pinctrl_soc_data {int dummy; } ;

/* Variables and functions */
 struct nmk_pinctrl_soc_data nmk_db8500_soc ; 

void nmk_pinctrl_db8500_init(const struct nmk_pinctrl_soc_data **soc)
{
	*soc = &nmk_db8500_soc;
}