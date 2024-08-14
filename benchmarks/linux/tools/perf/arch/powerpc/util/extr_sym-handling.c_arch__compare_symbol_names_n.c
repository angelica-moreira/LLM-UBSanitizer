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
 int strncmp (char const*,char const*,unsigned int) ; 

int arch__compare_symbol_names_n(const char *namea, const char *nameb,
				 unsigned int n)
{
	/* Skip over initial dot */
	if (*namea == '.')
		namea++;
	if (*nameb == '.')
		nameb++;

	return strncmp(namea, nameb, n);
}