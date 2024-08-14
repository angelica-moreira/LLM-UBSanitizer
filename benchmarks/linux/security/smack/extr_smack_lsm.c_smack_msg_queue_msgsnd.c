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
struct msg_msg {int dummy; } ;
struct kern_ipc_perm {int dummy; } ;

/* Variables and functions */
 int smack_flags_to_may (int) ; 
 int smk_curacc_msq (struct kern_ipc_perm*,int) ; 

__attribute__((used)) static int smack_msg_queue_msgsnd(struct kern_ipc_perm *isp, struct msg_msg *msg,
				  int msqflg)
{
	int may;

	may = smack_flags_to_may(msqflg);
	return smk_curacc_msq(isp, may);
}