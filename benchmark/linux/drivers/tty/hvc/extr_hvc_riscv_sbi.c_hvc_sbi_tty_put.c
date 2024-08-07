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
 int /*<<< orphan*/  sbi_console_putchar (char const) ; 

__attribute__((used)) static int hvc_sbi_tty_put(uint32_t vtermno, const char *buf, int count)
{
	int i;

	for (i = 0; i < count; i++)
		sbi_console_putchar(buf[i]);

	return i;
}