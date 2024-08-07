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
struct smack_known {int dummy; } ;
struct kern_ipc_perm {int dummy; } ;

/* Variables and functions */
 struct smack_known** smack_ipc (struct kern_ipc_perm*) ; 
 struct smack_known* smk_of_current () ; 

__attribute__((used)) static int smack_ipc_alloc_security(struct kern_ipc_perm *isp)
{
	struct smack_known **blob = smack_ipc(isp);

	*blob = smk_of_current();
	return 0;
}