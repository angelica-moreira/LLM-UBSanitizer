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
 int /*<<< orphan*/  DMWARN (char*) ; 
 int EINVAL ; 
 scalar_t__ strchr (char const*,char) ; 

__attribute__((used)) static int check_name(const char *name)
{
	if (strchr(name, '/')) {
		DMWARN("invalid device name");
		return -EINVAL;
	}

	return 0;
}