#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int fraghdr; } ;
struct sock_xprt {TYPE_1__ recv; } ;

/* Variables and functions */
 int /*<<< orphan*/  RPC_LAST_STREAM_FRAGMENT ; 
 int cpu_to_be32 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
xs_read_stream_request_done(struct sock_xprt *transport)
{
	return transport->recv.fraghdr & cpu_to_be32(RPC_LAST_STREAM_FRAGMENT);
}