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

int get_line_no(const char *text)
{
	int i;
	int total = 1;

	if (!text)
		return 0;

	for (i = 0; text[i] != '\0'; i++)
		if (text[i] == '\n')
			total++;
	return total;
}