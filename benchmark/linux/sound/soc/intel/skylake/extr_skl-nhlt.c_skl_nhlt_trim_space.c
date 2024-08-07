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
 int /*<<< orphan*/  isspace (char) ; 

__attribute__((used)) static void skl_nhlt_trim_space(char *trim)
{
	char *s = trim;
	int cnt;
	int i;

	cnt = 0;
	for (i = 0; s[i]; i++) {
		if (!isspace(s[i]))
			s[cnt++] = s[i];
	}

	s[cnt] = '\0';
}