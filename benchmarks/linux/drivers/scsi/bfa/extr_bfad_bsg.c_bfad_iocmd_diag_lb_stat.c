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
struct bfad_s {int /*<<< orphan*/  bfad_lock; int /*<<< orphan*/  bfa; } ;
struct bfa_bsg_diag_lb_stat_s {int /*<<< orphan*/  status; } ;

/* Variables and functions */
 int /*<<< orphan*/  bfa_fcdiag_lb_is_running (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bfa_trc (struct bfad_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int
bfad_iocmd_diag_lb_stat(struct bfad_s *bfad, void *cmd)
{
	struct bfa_bsg_diag_lb_stat_s *iocmd =
			(struct bfa_bsg_diag_lb_stat_s *)cmd;
	unsigned long	flags;

	spin_lock_irqsave(&bfad->bfad_lock, flags);
	iocmd->status = bfa_fcdiag_lb_is_running(&bfad->bfa);
	spin_unlock_irqrestore(&bfad->bfad_lock, flags);
	bfa_trc(bfad, iocmd->status);

	return 0;
}