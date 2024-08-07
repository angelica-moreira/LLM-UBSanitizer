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
struct hci_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  HCI_DEV_RESUME ; 
 int /*<<< orphan*/  hci_sock_dev_event (struct hci_dev*,int /*<<< orphan*/ ) ; 

int hci_resume_dev(struct hci_dev *hdev)
{
	hci_sock_dev_event(hdev, HCI_DEV_RESUME);
	return 0;
}