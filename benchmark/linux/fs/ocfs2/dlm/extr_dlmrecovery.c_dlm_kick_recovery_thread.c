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
struct dlm_ctxt {int /*<<< orphan*/  dlm_reco_thread_wq; } ;

/* Variables and functions */
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

void dlm_kick_recovery_thread(struct dlm_ctxt *dlm)
{
	/* wake the recovery thread
	 * this will wake the reco thread in one of three places
	 * 1) sleeping with no recovery happening
	 * 2) sleeping with recovery mastered elsewhere
	 * 3) recovery mastered here, waiting on reco data */

	wake_up(&dlm->dlm_reco_thread_wq);
}