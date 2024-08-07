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
typedef  scalar_t__ u32 ;
struct kern_ipc_perm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  call_void_hook (int /*<<< orphan*/ ,struct kern_ipc_perm*,scalar_t__*) ; 
 int /*<<< orphan*/  ipc_getsecid ; 

void security_ipc_getsecid(struct kern_ipc_perm *ipcp, u32 *secid)
{
	*secid = 0;
	call_void_hook(ipc_getsecid, ipcp, secid);
}