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
 scalar_t__ isdigit (char const) ; 

__attribute__((used)) static bool parse_n(const char *s, unsigned long *res, const char **next_s)
{
	if (!isdigit(*s))
		return false;

	*res = 0;
	while (isdigit(*s)) {
		*res = *res * 10 + (*s - '0');
		++s;
	}

	*next_s = s;
	return true;
}