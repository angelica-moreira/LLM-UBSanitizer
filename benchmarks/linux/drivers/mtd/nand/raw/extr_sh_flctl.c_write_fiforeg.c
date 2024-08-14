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
struct sh_flctl {int /*<<< orphan*/ * done_buff; } ;

/* Variables and functions */
 int /*<<< orphan*/  FLDTFIFO (struct sh_flctl*) ; 
 int /*<<< orphan*/  cpu_to_be32 (unsigned long) ; 
 int /*<<< orphan*/  wait_wfifo_ready (struct sh_flctl*) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void write_fiforeg(struct sh_flctl *flctl, int rlen,
						unsigned int offset)
{
	int i, len_4align;
	unsigned long *buf = (unsigned long *)&flctl->done_buff[offset];

	len_4align = (rlen + 3) / 4;
	for (i = 0; i < len_4align; i++) {
		wait_wfifo_ready(flctl);
		writel(cpu_to_be32(buf[i]), FLDTFIFO(flctl));
	}
}