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
struct sk_buff {int /*<<< orphan*/  sk; } ;

/* Variables and functions */
 int /*<<< orphan*/  pass_open_abort (int /*<<< orphan*/ ,struct sock*,struct sk_buff*) ; 

__attribute__((used)) static void bl_pass_open_abort(struct sock *lsk, struct sk_buff *skb)
{
	pass_open_abort(skb->sk, lsk, skb);
}