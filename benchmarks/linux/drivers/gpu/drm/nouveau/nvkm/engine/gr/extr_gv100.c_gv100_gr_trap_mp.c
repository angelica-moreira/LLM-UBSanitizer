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
struct gf100_gr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gv100_gr_trap_sm (struct gf100_gr*,int,int,int) ; 

__attribute__((used)) static void
gv100_gr_trap_mp(struct gf100_gr *gr, int gpc, int tpc)
{
	gv100_gr_trap_sm(gr, gpc, tpc, 0);
	gv100_gr_trap_sm(gr, gpc, tpc, 1);
}