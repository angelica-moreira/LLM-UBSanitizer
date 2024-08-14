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
struct savagefb_par {int paletteEnabled; } ;

/* Variables and functions */
 int /*<<< orphan*/  vga_in8 (int,struct savagefb_par*) ; 
 int /*<<< orphan*/  vga_out8 (int,int,struct savagefb_par*) ; 

__attribute__((used)) static inline void VGAenablePalette(struct savagefb_par *par)
{
	vga_in8(0x3da, par);
	vga_out8(0x3c0, 0x00, par);
	par->paletteEnabled = 1;
}