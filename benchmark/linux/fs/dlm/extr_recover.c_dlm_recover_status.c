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
struct dlm_ls {int /*<<< orphan*/  ls_recover_lock; int /*<<< orphan*/  ls_recover_status; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

uint32_t dlm_recover_status(struct dlm_ls *ls)
{
	uint32_t status;
	spin_lock(&ls->ls_recover_lock);
	status = ls->ls_recover_status;
	spin_unlock(&ls->ls_recover_lock);
	return status;
}