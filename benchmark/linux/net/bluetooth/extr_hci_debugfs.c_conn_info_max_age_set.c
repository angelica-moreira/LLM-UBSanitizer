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
typedef  scalar_t__ u64 ;
struct hci_dev {scalar_t__ conn_info_min_age; scalar_t__ conn_info_max_age; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  hci_dev_lock (struct hci_dev*) ; 
 int /*<<< orphan*/  hci_dev_unlock (struct hci_dev*) ; 

__attribute__((used)) static int conn_info_max_age_set(void *data, u64 val)
{
	struct hci_dev *hdev = data;

	if (val == 0 || val < hdev->conn_info_min_age)
		return -EINVAL;

	hci_dev_lock(hdev);
	hdev->conn_info_max_age = val;
	hci_dev_unlock(hdev);

	return 0;
}