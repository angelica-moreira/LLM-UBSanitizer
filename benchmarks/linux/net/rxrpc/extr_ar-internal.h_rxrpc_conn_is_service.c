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
struct rxrpc_connection {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rxrpc_conn_is_client (struct rxrpc_connection const*) ; 

__attribute__((used)) static inline bool rxrpc_conn_is_service(const struct rxrpc_connection *conn)
{
	return !rxrpc_conn_is_client(conn);
}