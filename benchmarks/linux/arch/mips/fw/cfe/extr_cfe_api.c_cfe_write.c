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
 int cfe_writeblk (int,int /*<<< orphan*/ ,char const*,int) ; 

int cfe_write(int handle, const char *buffer, int length)
{
	return cfe_writeblk(handle, 0, buffer, length);
}