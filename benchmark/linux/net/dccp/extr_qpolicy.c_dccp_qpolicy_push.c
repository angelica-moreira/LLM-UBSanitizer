#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct TYPE_4__ {size_t dccps_qpolicy; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* push ) (struct sock*,struct sk_buff*) ;} ;

/* Variables and functions */
 TYPE_2__* dccp_sk (struct sock*) ; 
 TYPE_1__* qpol_table ; 
 int /*<<< orphan*/  stub1 (struct sock*,struct sk_buff*) ; 

void dccp_qpolicy_push(struct sock *sk, struct sk_buff *skb)
{
	qpol_table[dccp_sk(sk)->dccps_qpolicy].push(sk, skb);
}