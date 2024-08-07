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
struct sock {scalar_t__ sk_sndbuf; int /*<<< orphan*/  sk_wmem_alloc; } ;

/* Variables and functions */
 size_t refcount_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int rxrpc_writable(struct sock *sk)
{
	return refcount_read(&sk->sk_wmem_alloc) < (size_t) sk->sk_sndbuf;
}