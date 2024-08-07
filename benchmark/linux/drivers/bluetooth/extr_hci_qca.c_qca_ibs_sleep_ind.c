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
struct hci_uart {int dummy; } ;
struct hci_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT_DBG (char*,struct hci_uart*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HCI_IBS_SLEEP_IND ; 
 int /*<<< orphan*/  device_want_to_sleep (struct hci_uart*) ; 
 struct hci_uart* hci_get_drvdata (struct hci_dev*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 

__attribute__((used)) static int qca_ibs_sleep_ind(struct hci_dev *hdev, struct sk_buff *skb)
{
	struct hci_uart *hu = hci_get_drvdata(hdev);

	BT_DBG("hu %p recv hci ibs cmd 0x%x", hu, HCI_IBS_SLEEP_IND);

	device_want_to_sleep(hu);

	kfree_skb(skb);
	return 0;
}