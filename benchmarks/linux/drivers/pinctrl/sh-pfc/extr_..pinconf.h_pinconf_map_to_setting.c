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
struct pinctrl_setting {int dummy; } ;
struct pinctrl_map {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline int pinconf_map_to_setting(const struct pinctrl_map *map,
			  struct pinctrl_setting *setting)
{
	return 0;
}