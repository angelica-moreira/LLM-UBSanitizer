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
struct nfc_hci_dev {int /*<<< orphan*/  llc; } ;

/* Variables and functions */
 int /*<<< orphan*/  nfc_llc_rcv_from_drv (int /*<<< orphan*/ ,struct sk_buff*) ; 

void nfc_hci_recv_frame(struct nfc_hci_dev *hdev, struct sk_buff *skb)
{
	nfc_llc_rcv_from_drv(hdev->llc, skb);
}