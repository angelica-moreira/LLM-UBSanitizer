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
struct si_sm_io {unsigned int regspacing; scalar_t__ addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  writeb (unsigned char,scalar_t__) ; 

__attribute__((used)) static void intf_mem_outb(const struct si_sm_io *io, unsigned int offset,
			  unsigned char b)
{
	writeb(b, (io->addr)+(offset * io->regspacing));
}