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
struct lm_lockstruct {int /*<<< orphan*/  ls_recover_spin; int /*<<< orphan*/  ls_recover_flags; int /*<<< orphan*/  ls_recover_start; int /*<<< orphan*/  ls_recover_block; } ;
struct gfs2_sbd {struct lm_lockstruct sd_lockstruct; } ;

/* Variables and functions */
 int /*<<< orphan*/  DFL_BLOCK_LOCKS ; 
 int /*<<< orphan*/  DFL_DLM_RECOVERY ; 
 int /*<<< orphan*/  DFL_FIRST_MOUNT ; 
 int /*<<< orphan*/  DFL_MOUNT_DONE ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void gdlm_recover_prep(void *arg)
{
	struct gfs2_sbd *sdp = arg;
	struct lm_lockstruct *ls = &sdp->sd_lockstruct;

	spin_lock(&ls->ls_recover_spin);
	ls->ls_recover_block = ls->ls_recover_start;
	set_bit(DFL_DLM_RECOVERY, &ls->ls_recover_flags);

	if (!test_bit(DFL_MOUNT_DONE, &ls->ls_recover_flags) ||
	     test_bit(DFL_FIRST_MOUNT, &ls->ls_recover_flags)) {
		spin_unlock(&ls->ls_recover_spin);
		return;
	}
	set_bit(DFL_BLOCK_LOCKS, &ls->ls_recover_flags);
	spin_unlock(&ls->ls_recover_spin);
}