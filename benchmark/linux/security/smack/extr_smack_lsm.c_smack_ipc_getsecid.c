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
typedef  int /*<<< orphan*/  u32 ;
struct smack_known {int /*<<< orphan*/  smk_secid; } ;
struct kern_ipc_perm {int dummy; } ;

/* Variables and functions */
 struct smack_known** smack_ipc (struct kern_ipc_perm*) ; 

__attribute__((used)) static void smack_ipc_getsecid(struct kern_ipc_perm *ipp, u32 *secid)
{
	struct smack_known **blob = smack_ipc(ipp);
	struct smack_known *iskp = *blob;

	*secid = iskp->smk_secid;
}