#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  sync; int /*<<< orphan*/  mode; } ;
struct TYPE_6__ {TYPE_1__ tt; } ;
struct atafb_par {int /*<<< orphan*/  screen_base; TYPE_2__ hw; } ;
struct TYPE_8__ {int bas_hi; int bas_md; int bas_lo; int /*<<< orphan*/  syncmode; } ;
struct TYPE_7__ {int /*<<< orphan*/  tt_shiftmode; } ;

/* Variables and functions */
 int /*<<< orphan*/  atari_stram_to_virt (unsigned long) ; 
 TYPE_4__ shifter_st ; 
 TYPE_3__ shifter_tt ; 

__attribute__((used)) static void tt_get_par(struct atafb_par *par)
{
	unsigned long addr;
	par->hw.tt.mode = shifter_tt.tt_shiftmode;
	par->hw.tt.sync = shifter_st.syncmode;
	addr = ((shifter_st.bas_hi & 0xff) << 16) |
	       ((shifter_st.bas_md & 0xff) << 8)  |
	       ((shifter_st.bas_lo & 0xff));
	par->screen_base = atari_stram_to_virt(addr);
}