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
struct rpc_xprt {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  XPRT_CWND_WAIT ; 
 int /*<<< orphan*/  __xprt_lock_write_next_cong (struct rpc_xprt*) ; 
 scalar_t__ test_and_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void xprt_clear_congestion_window_wait_locked(struct rpc_xprt *xprt)
{
	if (test_and_clear_bit(XPRT_CWND_WAIT, &xprt->state))
		__xprt_lock_write_next_cong(xprt);
}