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
typedef  int /*<<< orphan*/  u8 ;
struct sk_buff {int len; scalar_t__ data; } ;
struct rtllib_info_element {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  addr2; } ;
struct rtllib_assoc_request_frame {TYPE_1__ header; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ether_addr_copy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netdev_dbg (struct net_device*,char*,int) ; 

__attribute__((used)) static int assoc_rq_parse(struct net_device *dev, struct sk_buff *skb, u8 *dest)
{
	struct rtllib_assoc_request_frame *a;

	if (skb->len < (sizeof(struct rtllib_assoc_request_frame) -
		sizeof(struct rtllib_info_element))) {
		netdev_dbg(dev, "invalid len in auth request:%d\n", skb->len);
		return -1;
	}

	a = (struct rtllib_assoc_request_frame *) skb->data;

	ether_addr_copy(dest, a->header.addr2);

	return 0;
}