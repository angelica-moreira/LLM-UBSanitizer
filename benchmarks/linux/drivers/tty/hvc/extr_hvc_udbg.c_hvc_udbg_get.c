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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int udbg_getc_poll () ; 

__attribute__((used)) static int hvc_udbg_get(uint32_t vtermno, char *buf, int count)
{
	int i, c;

	if (!udbg_getc_poll)
		return 0;

	for (i = 0; i < count; i++) {
		if ((c = udbg_getc_poll()) == -1)
			break;
		buf[i] = c;
	}

	return i;
}