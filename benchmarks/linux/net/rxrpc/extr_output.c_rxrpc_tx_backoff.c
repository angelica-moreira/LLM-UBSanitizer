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
typedef  scalar_t__ u16 ;
struct rxrpc_call {int /*<<< orphan*/  tx_backoff; } ;

/* Variables and functions */
 scalar_t__ HZ ; 
 scalar_t__ READ_ONCE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void rxrpc_tx_backoff(struct rxrpc_call *call, int ret)
{
	if (ret < 0) {
		u16 tx_backoff = READ_ONCE(call->tx_backoff);

		if (tx_backoff < HZ)
			WRITE_ONCE(call->tx_backoff, tx_backoff + 1);
	} else {
		WRITE_ONCE(call->tx_backoff, 0);
	}
}