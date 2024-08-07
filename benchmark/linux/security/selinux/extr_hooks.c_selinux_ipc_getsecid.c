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
struct kern_ipc_perm {int dummy; } ;
struct ipc_security_struct {int /*<<< orphan*/  sid; } ;

/* Variables and functions */
 struct ipc_security_struct* selinux_ipc (struct kern_ipc_perm*) ; 

__attribute__((used)) static void selinux_ipc_getsecid(struct kern_ipc_perm *ipcp, u32 *secid)
{
	struct ipc_security_struct *isec = selinux_ipc(ipcp);
	*secid = isec->sid;
}