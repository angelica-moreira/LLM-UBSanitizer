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
struct TYPE_2__ {int /*<<< orphan*/  saddr; } ;

/* Variables and functions */
 TYPE_1__* ip_hdr (struct sk_buff*) ; 
 int vti_rcv (struct sk_buff*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int vti_rcv_tunnel(struct sk_buff *skb)
{
	return vti_rcv(skb, ip_hdr(skb)->saddr, true);
}