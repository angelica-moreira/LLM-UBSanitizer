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
struct wkup_m3_ipc {int dummy; } ;

/* Variables and functions */
 int M3_STATUS_RESP_MASK ; 
 unsigned int __ffs (int) ; 
 int wkup_m3_ctrl_ipc_read (struct wkup_m3_ipc*,int) ; 

__attribute__((used)) static int wkup_m3_request_pm_status(struct wkup_m3_ipc *m3_ipc)
{
	unsigned int i;
	int val;

	val = wkup_m3_ctrl_ipc_read(m3_ipc, 1);

	i = M3_STATUS_RESP_MASK & val;
	i >>= __ffs(M3_STATUS_RESP_MASK);

	return i;
}