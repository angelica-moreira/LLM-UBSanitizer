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

const char *get_line(const char *text, int line_no)
{
	int i;
	int lines = 0;

	if (!text)
		return NULL;

	for (i = 0; text[i] != '\0' && lines < line_no; i++)
		if (text[i] == '\n')
			lines++;
	return text+i;
}