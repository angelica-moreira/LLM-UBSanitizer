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
struct socket {int dummy; } ;
struct rxrpc_call {scalar_t__ state; int /*<<< orphan*/  acks_latest; } ;

/* Variables and functions */
 scalar_t__ RXRPC_CALL_COMPLETE ; 

bool rxrpc_kernel_check_life(const struct socket *sock,
			     const struct rxrpc_call *call,
			     u32 *_life)
{
	*_life = call->acks_latest;
	return call->state != RXRPC_CALL_COMPLETE;
}