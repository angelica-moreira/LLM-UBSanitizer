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
struct sk_buff {int dummy; } ;
struct rtllib_device {int dummy; } ;

/* Variables and functions */
 struct sk_buff* rtllib_pspoll_func (struct rtllib_device*) ; 
 int /*<<< orphan*/  softmac_ps_mgmt_xmit (struct sk_buff*,struct rtllib_device*) ; 

void rtllib_sta_ps_send_pspoll_frame(struct rtllib_device *ieee)
{
	struct sk_buff *buf = rtllib_pspoll_func(ieee);

	if (buf)
		softmac_ps_mgmt_xmit(buf, ieee);
}