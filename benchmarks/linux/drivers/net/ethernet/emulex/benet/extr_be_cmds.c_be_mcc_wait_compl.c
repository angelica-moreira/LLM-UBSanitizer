#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  used; } ;
struct be_mcc_obj {TYPE_2__ q; } ;
struct be_adapter {TYPE_1__* pdev; struct be_mcc_obj mcc_obj; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BE_ERROR_ANY ; 
 int /*<<< orphan*/  BE_ERROR_FW ; 
 int EIO ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 scalar_t__ be_check_error (struct be_adapter*,int /*<<< orphan*/ ) ; 
 int be_process_mcc (struct be_adapter*) ; 
 int /*<<< orphan*/  be_set_error (struct be_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int mcc_timeout ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int be_mcc_wait_compl(struct be_adapter *adapter)
{
#define mcc_timeout		12000 /* 12s timeout */
	int i, status = 0;
	struct be_mcc_obj *mcc_obj = &adapter->mcc_obj;

	for (i = 0; i < mcc_timeout; i++) {
		if (be_check_error(adapter, BE_ERROR_ANY))
			return -EIO;

		status = be_process_mcc(adapter);

		if (atomic_read(&mcc_obj->q.used) == 0)
			break;
		usleep_range(500, 1000);
	}
	if (i == mcc_timeout) {
		dev_err(&adapter->pdev->dev, "FW not responding\n");
		be_set_error(adapter, BE_ERROR_FW);
		return -EIO;
	}
	return status;
}