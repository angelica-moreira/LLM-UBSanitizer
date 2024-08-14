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
struct sembuf {int dummy; } ;
struct kern_ipc_perm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAY_READWRITE ; 
 int smk_curacc_sem (struct kern_ipc_perm*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int smack_sem_semop(struct kern_ipc_perm *isp, struct sembuf *sops,
			   unsigned nsops, int alter)
{
	return smk_curacc_sem(isp, MAY_READWRITE);
}