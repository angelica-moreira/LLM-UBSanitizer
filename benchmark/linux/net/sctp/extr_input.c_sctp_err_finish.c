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
struct sctp_transport {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bh_unlock_sock (struct sock*) ; 
 int /*<<< orphan*/  sctp_transport_put (struct sctp_transport*) ; 

void sctp_err_finish(struct sock *sk, struct sctp_transport *t)
{
	bh_unlock_sock(sk);
	sctp_transport_put(t);
}