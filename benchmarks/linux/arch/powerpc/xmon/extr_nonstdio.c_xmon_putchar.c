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
 int xmon_write (char*,int) ; 

int xmon_putchar(int c)
{
	char ch = c;

	if (c == '\n')
		xmon_putchar('\r');
	return xmon_write(&ch, 1) == 1? c: -1;
}