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
struct bfa_msgq_cmdq {int /*<<< orphan*/  flags; } ;
typedef  enum cmdq_event { ____Placeholder_cmdq_event } cmdq_event ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_MSGQ_CMDQ_F_DB_UPDATE ; 
#define  CMDQ_E_FAIL 131 
#define  CMDQ_E_POST 130 
#define  CMDQ_E_START 129 
#define  CMDQ_E_STOP 128 
 int /*<<< orphan*/  bfa_fsm_set_state (struct bfa_msgq_cmdq*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_sm_fault (int) ; 
 int /*<<< orphan*/  cmdq_sm_init_wait ; 

__attribute__((used)) static void
cmdq_sm_stopped(struct bfa_msgq_cmdq *cmdq, enum cmdq_event event)
{
	switch (event) {
	case CMDQ_E_START:
		bfa_fsm_set_state(cmdq, cmdq_sm_init_wait);
		break;

	case CMDQ_E_STOP:
	case CMDQ_E_FAIL:
		/* No-op */
		break;

	case CMDQ_E_POST:
		cmdq->flags |= BFA_MSGQ_CMDQ_F_DB_UPDATE;
		break;

	default:
		bfa_sm_fault(event);
	}
}