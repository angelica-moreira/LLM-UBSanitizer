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
struct xpc_partition {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  XPC_P_ASR_ACTIVATE_UV ; 
 int /*<<< orphan*/  xpc_send_local_activate_IRQ_uv (struct xpc_partition*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
xpc_request_partition_reactivation_uv(struct xpc_partition *part)
{
	xpc_send_local_activate_IRQ_uv(part, XPC_P_ASR_ACTIVATE_UV);
}