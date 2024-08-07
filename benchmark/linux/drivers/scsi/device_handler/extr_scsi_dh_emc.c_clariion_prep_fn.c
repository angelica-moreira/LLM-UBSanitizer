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
struct scsi_device {struct clariion_dh_data* handler_data; } ;
struct request {int /*<<< orphan*/  rq_flags; } ;
struct clariion_dh_data {scalar_t__ lun_state; } ;
typedef  int /*<<< orphan*/  blk_status_t ;

/* Variables and functions */
 int /*<<< orphan*/  BLK_STS_IOERR ; 
 int /*<<< orphan*/  BLK_STS_OK ; 
 scalar_t__ CLARIION_LUN_OWNED ; 
 int /*<<< orphan*/  RQF_QUIET ; 

__attribute__((used)) static blk_status_t clariion_prep_fn(struct scsi_device *sdev,
		struct request *req)
{
	struct clariion_dh_data *h = sdev->handler_data;

	if (h->lun_state != CLARIION_LUN_OWNED) {
		req->rq_flags |= RQF_QUIET;
		return BLK_STS_IOERR;
	}

	return BLK_STS_OK;
}