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
struct sk_buff {int dummy; } ;
struct TYPE_2__ {int ifindex; } ;

/* Variables and functions */
 TYPE_1__* icmp6_dev (struct sk_buff const*) ; 

__attribute__((used)) static int icmp6_iif(const struct sk_buff *skb)
{
	return icmp6_dev(skb)->ifindex;
}