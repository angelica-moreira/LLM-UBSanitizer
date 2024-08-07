#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct kern_ipc_perm {int /*<<< orphan*/  key; } ;
struct ipc_security_struct {int /*<<< orphan*/  sclass; int /*<<< orphan*/  sid; } ;
struct TYPE_2__ {int /*<<< orphan*/  ipc_id; } ;
struct common_audit_data {TYPE_1__ u; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  LSM_AUDIT_DATA_IPC ; 
 int avc_has_perm (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct common_audit_data*) ; 
 int /*<<< orphan*/  current_sid () ; 
 struct ipc_security_struct* selinux_ipc (struct kern_ipc_perm*) ; 
 int /*<<< orphan*/  selinux_state ; 

__attribute__((used)) static int ipc_has_perm(struct kern_ipc_perm *ipc_perms,
			u32 perms)
{
	struct ipc_security_struct *isec;
	struct common_audit_data ad;
	u32 sid = current_sid();

	isec = selinux_ipc(ipc_perms);

	ad.type = LSM_AUDIT_DATA_IPC;
	ad.u.ipc_id = ipc_perms->key;

	return avc_has_perm(&selinux_state,
			    sid, isec->sid, isec->sclass, perms, &ad);
}