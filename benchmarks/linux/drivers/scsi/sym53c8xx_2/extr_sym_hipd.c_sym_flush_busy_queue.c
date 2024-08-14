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
struct sym_hcb {int /*<<< orphan*/  busy_ccbq; int /*<<< orphan*/  comp_ccbq; } ;

/* Variables and functions */
 int /*<<< orphan*/  sym_flush_comp_queue (struct sym_hcb*,int) ; 
 int /*<<< orphan*/  sym_que_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sym_que_splice (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sym_flush_busy_queue (struct sym_hcb *np, int cam_status)
{
	/*
	 *  Move all active CCBs to the COMP queue 
	 *  and flush this queue.
	 */
	sym_que_splice(&np->busy_ccbq, &np->comp_ccbq);
	sym_que_init(&np->busy_ccbq);
	sym_flush_comp_queue(np, cam_status);
}