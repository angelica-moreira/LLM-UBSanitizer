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
struct request_sock {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  pktopts; int /*<<< orphan*/  ipv6_opt; } ;

/* Variables and functions */
 TYPE_1__* inet_rsk (struct request_sock*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree_skb (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tcp_v6_reqsk_destructor(struct request_sock *req)
{
	kfree(inet_rsk(req)->ipv6_opt);
	kfree_skb(inet_rsk(req)->pktopts);
}