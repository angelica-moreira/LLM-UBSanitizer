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
struct TYPE_2__ {int /*<<< orphan*/  protocol; } ;

/* Variables and functions */
 TYPE_1__* ip_hdr (struct sk_buff*) ; 
 int xfrm4_rcv_spi (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int xfrm4_rcv(struct sk_buff *skb)
{
	return xfrm4_rcv_spi(skb, ip_hdr(skb)->protocol, 0);
}