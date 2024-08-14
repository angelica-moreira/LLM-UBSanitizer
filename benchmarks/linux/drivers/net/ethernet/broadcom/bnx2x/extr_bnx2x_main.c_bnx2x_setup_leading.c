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
struct bnx2x {int /*<<< orphan*/ * fp; } ;

/* Variables and functions */
 scalar_t__ IS_PF (struct bnx2x*) ; 
 int bnx2x_setup_queue (struct bnx2x*,int /*<<< orphan*/ *,int) ; 
 int bnx2x_vfpf_setup_q (struct bnx2x*,int /*<<< orphan*/ *,int) ; 

int bnx2x_setup_leading(struct bnx2x *bp)
{
	if (IS_PF(bp))
		return bnx2x_setup_queue(bp, &bp->fp[0], true);
	else /* VF */
		return bnx2x_vfpf_setup_q(bp, &bp->fp[0], true);
}