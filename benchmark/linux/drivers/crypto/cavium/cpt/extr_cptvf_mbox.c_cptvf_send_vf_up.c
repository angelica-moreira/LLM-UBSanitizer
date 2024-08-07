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
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct cpt_vf {struct pci_dev* pdev; } ;
struct cpt_mbox {int /*<<< orphan*/  msg; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPT_MSG_VF_UP ; 
 int EBUSY ; 
 scalar_t__ cptvf_send_msg_to_pf_timeout (struct cpt_vf*,struct cpt_mbox*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 

int cptvf_send_vf_up(struct cpt_vf *cptvf)
{
	struct pci_dev *pdev = cptvf->pdev;
	struct cpt_mbox mbx = {};

	mbx.msg = CPT_MSG_VF_UP;
	if (cptvf_send_msg_to_pf_timeout(cptvf, &mbx)) {
		dev_err(&pdev->dev, "PF didn't respond to UP msg\n");
		return -EBUSY;
	}

	return 0;
}