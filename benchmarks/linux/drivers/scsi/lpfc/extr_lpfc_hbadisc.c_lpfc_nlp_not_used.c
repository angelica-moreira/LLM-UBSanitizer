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
struct lpfc_nodelist {int /*<<< orphan*/  kref; int /*<<< orphan*/  nlp_flag; int /*<<< orphan*/  nlp_DID; int /*<<< orphan*/  vport; } ;

/* Variables and functions */
 int /*<<< orphan*/  LPFC_DISC_TRC_NODE ; 
 int kref_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lpfc_debugfs_disc_trc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ lpfc_nlp_put (struct lpfc_nodelist*) ; 

int
lpfc_nlp_not_used(struct lpfc_nodelist *ndlp)
{
	lpfc_debugfs_disc_trc(ndlp->vport, LPFC_DISC_TRC_NODE,
		"node not used:   did:x%x flg:x%x refcnt:x%x",
		ndlp->nlp_DID, ndlp->nlp_flag,
		kref_read(&ndlp->kref));
	if (kref_read(&ndlp->kref) == 1)
		if (lpfc_nlp_put(ndlp))
			return 1;
	return 0;
}