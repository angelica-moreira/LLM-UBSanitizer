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
struct __sk_buff {int dummy; } ;

/* Variables and functions */
 int __do_push_ll_and_redirect (struct __sk_buff*) ; 

int do_push_ll_and_redirect_silent(struct __sk_buff *skb)
{
	return __do_push_ll_and_redirect(skb);
}