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
struct posix_clock {int dummy; } ;
typedef  int /*<<< orphan*/  fmode_t ;

/* Variables and functions */

int ptp_open(struct posix_clock *pc, fmode_t fmode)
{
	return 0;
}