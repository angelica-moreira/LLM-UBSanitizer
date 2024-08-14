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
 int /*<<< orphan*/  strcmp (char*,char const*) ; 
 int /*<<< orphan*/  strncmp (char const*,char*,int) ; 

int snd_info_check_reserved_words(const char *str)
{
	static char *reserved[] =
	{
		"version",
		"meminfo",
		"memdebug",
		"detect",
		"devices",
		"oss",
		"cards",
		"timers",
		"synth",
		"pcm",
		"seq",
		NULL
	};
	char **xstr = reserved;

	while (*xstr) {
		if (!strcmp(*xstr, str))
			return 0;
		xstr++;
	}
	if (!strncmp(str, "card", 4))
		return 0;
	return 1;
}