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
struct tridentfb_par {int /*<<< orphan*/  io_virt; } ;

/* Variables and functions */
 int /*<<< orphan*/  vga_mm_wgfx (int /*<<< orphan*/ ,int,unsigned char) ; 

__attribute__((used)) static inline void write3CE(struct tridentfb_par *par, int reg,
			    unsigned char val)
{
	vga_mm_wgfx(par->io_virt, reg, val);
}