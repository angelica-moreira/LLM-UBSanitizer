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
struct kern_ipc_perm {int dummy; } ;

/* Variables and functions */
 int call_int_hook (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct kern_ipc_perm*,int) ; 
 int /*<<< orphan*/  sem_associate ; 

int security_sem_associate(struct kern_ipc_perm *sma, int semflg)
{
	return call_int_hook(sem_associate, 0, sma, semflg);
}