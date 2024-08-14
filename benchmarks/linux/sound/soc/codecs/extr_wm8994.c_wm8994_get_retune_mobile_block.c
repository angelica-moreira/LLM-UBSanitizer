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

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static int wm8994_get_retune_mobile_block(const char *name)
{
	if (strcmp(name, "AIF1.1 EQ Mode") == 0)
		return 0;
	if (strcmp(name, "AIF1.2 EQ Mode") == 0)
		return 1;
	if (strcmp(name, "AIF2 EQ Mode") == 0)
		return 2;
	return -EINVAL;
}