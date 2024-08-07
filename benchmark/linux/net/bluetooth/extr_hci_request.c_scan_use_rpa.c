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
 int /*<<< orphan*/  HCI_PRIVACY ; 
 int hci_dev_test_flag (struct hci_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool scan_use_rpa(struct hci_dev *hdev)
{
	return hci_dev_test_flag(hdev, HCI_PRIVACY);
}