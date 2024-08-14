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
typedef  int u16 ;
struct vc_data {int dummy; } ;
typedef  int a ;

/* Variables and functions */
 int scr_readw (int*) ; 
 int /*<<< orphan*/  scr_writew (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sticon_invert_region(struct vc_data *conp, u16 *p, int count)
{
    int col = 1; /* vga_can_do_color; */

    while (count--) {
	u16 a = scr_readw(p);

	if (col)
		a = ((a) & 0x88ff) | (((a) & 0x7000) >> 4) | (((a) & 0x0700) << 4);
	else
		a = ((a & 0x0700) == 0x0100) ? 0x7000 : 0x7700;

	scr_writew(a, p++);
    }
}