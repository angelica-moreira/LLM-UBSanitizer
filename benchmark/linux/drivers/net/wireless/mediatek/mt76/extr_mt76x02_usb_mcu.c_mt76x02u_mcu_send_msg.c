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
struct TYPE_2__ {int /*<<< orphan*/  mutex; } ;
struct mt76_usb {TYPE_1__ mcu; } ;
struct mt76_dev {struct mt76_usb usb; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  MT_CMD_HDR_LEN ; 
 int __mt76x02u_mcu_send_msg (struct mt76_dev*,struct sk_buff*,int,int) ; 
 struct sk_buff* mt76_mcu_msg_alloc (void const*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
mt76x02u_mcu_send_msg(struct mt76_dev *dev, int cmd, const void *data,
		      int len, bool wait_resp)
{
	struct mt76_usb *usb = &dev->usb;
	struct sk_buff *skb;
	int err;

	skb = mt76_mcu_msg_alloc(data, MT_CMD_HDR_LEN, len, 8);
	if (!skb)
		return -ENOMEM;

	mutex_lock(&usb->mcu.mutex);
	err = __mt76x02u_mcu_send_msg(dev, skb, cmd, wait_resp);
	mutex_unlock(&usb->mcu.mutex);

	return err;
}