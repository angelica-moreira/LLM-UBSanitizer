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
 int sscanf (char const*,char*,int*) ; 

__attribute__((used)) static inline int fw_major_num(const char *fw_ver)
{
	int fw_major = 0, i;

	i = sscanf(fw_ver, "%d.", &fw_major);
	if (i != 1)
		return 0;

	return fw_major;
}