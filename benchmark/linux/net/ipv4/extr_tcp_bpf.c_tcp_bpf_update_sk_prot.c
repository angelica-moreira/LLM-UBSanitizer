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
struct sock {scalar_t__ sk_family; } ;
struct TYPE_2__ {scalar_t__ msg_parser; } ;
struct sk_psock {TYPE_1__ progs; } ;

/* Variables and functions */
 scalar_t__ AF_INET6 ; 
 int TCP_BPF_BASE ; 
 int TCP_BPF_IPV4 ; 
 int TCP_BPF_IPV6 ; 
 int TCP_BPF_TX ; 
 int /*<<< orphan*/  sk_psock_update_proto (struct sock*,struct sk_psock*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ ** tcp_bpf_prots ; 

__attribute__((used)) static void tcp_bpf_update_sk_prot(struct sock *sk, struct sk_psock *psock)
{
	int family = sk->sk_family == AF_INET6 ? TCP_BPF_IPV6 : TCP_BPF_IPV4;
	int config = psock->progs.msg_parser   ? TCP_BPF_TX   : TCP_BPF_BASE;

	sk_psock_update_proto(sk, psock, &tcp_bpf_prots[family][config]);
}