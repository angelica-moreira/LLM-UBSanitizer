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
struct nci_nfcee_mode_set_cmd {int dummy; } ;
struct nci_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  NCI_OP_NFCEE_MODE_SET_CMD ; 
 int /*<<< orphan*/  nci_send_cmd (struct nci_dev*,int /*<<< orphan*/ ,int,struct nci_nfcee_mode_set_cmd*) ; 

__attribute__((used)) static void nci_nfcee_mode_set_req(struct nci_dev *ndev, unsigned long opt)
{
	struct nci_nfcee_mode_set_cmd *cmd =
					(struct nci_nfcee_mode_set_cmd *)opt;

	nci_send_cmd(ndev, NCI_OP_NFCEE_MODE_SET_CMD,
		     sizeof(struct nci_nfcee_mode_set_cmd), cmd);
}