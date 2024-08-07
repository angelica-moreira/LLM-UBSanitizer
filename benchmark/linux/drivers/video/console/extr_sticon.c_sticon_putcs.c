#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct vc_data {scalar_t__ vc_mode; } ;
struct TYPE_2__ {int cursor_y; int cursor_x; } ;

/* Variables and functions */
 int /*<<< orphan*/  CURSOR_DRAW_DELAY ; 
 scalar_t__ KD_TEXT ; 
 scalar_t__ console_blanked ; 
 int /*<<< orphan*/  cursor_undrawn () ; 
 TYPE_1__* p ; 
 int /*<<< orphan*/  scr_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sti_putc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sticon_sti ; 
 int /*<<< orphan*/  vbl_cursor_cnt ; 
 scalar_t__ vga_is_gfx ; 

__attribute__((used)) static void sticon_putcs(struct vc_data *conp, const unsigned short *s,
			 int count, int ypos, int xpos)
{
    int redraw_cursor = 0;

    if (vga_is_gfx || console_blanked)
	    return;

    if (conp->vc_mode != KD_TEXT)
    	    return;

#if 0
    if ((p->cursor_y == ypos) && (xpos <= p->cursor_x) &&
	(p->cursor_x < (xpos + count))) {
	    cursor_undrawn();
	    redraw_cursor = 1;
    }
#endif

    while (count--) {
	sti_putc(sticon_sti, scr_readw(s++), ypos, xpos++);
    }

    if (redraw_cursor)
	    vbl_cursor_cnt = CURSOR_DRAW_DELAY;
}