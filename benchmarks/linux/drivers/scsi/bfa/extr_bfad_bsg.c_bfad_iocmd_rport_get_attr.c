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
struct bfad_s {int /*<<< orphan*/  bfad_lock; int /*<<< orphan*/  bfa_fcs; } ;
struct bfa_fcs_rport_s {int dummy; } ;
struct bfa_fcs_lport_s {int dummy; } ;
struct bfa_bsg_rport_attr_s {int /*<<< orphan*/  status; int /*<<< orphan*/  attr; int /*<<< orphan*/  rpwwn; scalar_t__ pid; int /*<<< orphan*/  pwwn; int /*<<< orphan*/  vf_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_STATUS_OK ; 
 int /*<<< orphan*/  BFA_STATUS_UNKNOWN_LWWN ; 
 int /*<<< orphan*/  BFA_STATUS_UNKNOWN_RWWN ; 
 struct bfa_fcs_lport_s* bfa_fcs_lookup_port (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct bfa_fcs_rport_s* bfa_fcs_lport_get_rport_by_qualifier (struct bfa_fcs_lport_s*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  bfa_fcs_rport_get_attr (struct bfa_fcs_rport_s*,int /*<<< orphan*/ *) ; 
 struct bfa_fcs_rport_s* bfa_fcs_rport_lookup (struct bfa_fcs_lport_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_trc (struct bfad_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int
bfad_iocmd_rport_get_attr(struct bfad_s *bfad, void *cmd)
{
	struct bfa_bsg_rport_attr_s *iocmd = (struct bfa_bsg_rport_attr_s *)cmd;
	struct bfa_fcs_lport_s *fcs_port;
	struct bfa_fcs_rport_s *fcs_rport;
	unsigned long	flags;

	spin_lock_irqsave(&bfad->bfad_lock, flags);
	fcs_port = bfa_fcs_lookup_port(&bfad->bfa_fcs,
				iocmd->vf_id, iocmd->pwwn);
	if (fcs_port == NULL) {
		bfa_trc(bfad, 0);
		spin_unlock_irqrestore(&bfad->bfad_lock, flags);
		iocmd->status = BFA_STATUS_UNKNOWN_LWWN;
		goto out;
	}

	if (iocmd->pid)
		fcs_rport = bfa_fcs_lport_get_rport_by_qualifier(fcs_port,
						iocmd->rpwwn, iocmd->pid);
	else
		fcs_rport = bfa_fcs_rport_lookup(fcs_port, iocmd->rpwwn);
	if (fcs_rport == NULL) {
		bfa_trc(bfad, 0);
		spin_unlock_irqrestore(&bfad->bfad_lock, flags);
		iocmd->status = BFA_STATUS_UNKNOWN_RWWN;
		goto out;
	}

	bfa_fcs_rport_get_attr(fcs_rport, &iocmd->attr);
	spin_unlock_irqrestore(&bfad->bfad_lock, flags);
	iocmd->status = BFA_STATUS_OK;
out:
	return 0;
}