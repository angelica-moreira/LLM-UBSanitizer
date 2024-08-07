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
struct dlm_rsb {int /*<<< orphan*/  res_waitqueue; int /*<<< orphan*/  res_convertqueue; int /*<<< orphan*/  res_grantqueue; struct dlm_ls* res_ls; } ;
struct dlm_ls {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  purge_mstcpy_list (struct dlm_ls*,struct dlm_rsb*,int /*<<< orphan*/ *) ; 

void dlm_purge_mstcpy_locks(struct dlm_rsb *r)
{
	struct dlm_ls *ls = r->res_ls;

	purge_mstcpy_list(ls, r, &r->res_grantqueue);
	purge_mstcpy_list(ls, r, &r->res_convertqueue);
	purge_mstcpy_list(ls, r, &r->res_waitqueue);
}