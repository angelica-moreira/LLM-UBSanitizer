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
struct sock {int dummy; } ;
struct rxrpc_call {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static void rxrpc_dummy_notify_rx(struct sock *sk, struct rxrpc_call *rxcall,
				  unsigned long call_user_ID)
{
}