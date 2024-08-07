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
typedef  int /*<<< orphan*/  uint32_t ;
struct lpfc_vport {int dummy; } ;
struct lpfc_nodelist {int /*<<< orphan*/  nlp_state; } ;
struct lpfc_iocbq {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ELS_CMD_PRLO ; 
 int /*<<< orphan*/  lpfc_rcv_logo (struct lpfc_vport*,struct lpfc_nodelist*,struct lpfc_iocbq*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint32_t
lpfc_rcv_prlo_adisc_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
			  void *arg, uint32_t evt)
{
	struct lpfc_iocbq *cmdiocb;

	cmdiocb = (struct lpfc_iocbq *) arg;

	/* Treat like rcv logo */
	lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_PRLO);
	return ndlp->nlp_state;
}