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
struct xt_action_param {int dummy; } ;
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ip_hdrlen (struct sk_buff*) ; 
 unsigned int tcpoptstrip_mangle_packet (struct sk_buff*,struct xt_action_param const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int
tcpoptstrip_tg4(struct sk_buff *skb, const struct xt_action_param *par)
{
	return tcpoptstrip_mangle_packet(skb, par, ip_hdrlen(skb));
}