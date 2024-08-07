#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {TYPE_3__* private_data; } ;
struct TYPE_9__ {int /*<<< orphan*/  pi; } ;
struct TYPE_8__ {int /*<<< orphan*/  bio; TYPE_4__* rq_disk; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLK_STS_IOERR ; 
 scalar_t__ READ ; 
 scalar_t__ WRITE ; 
 int /*<<< orphan*/  bio_data (int /*<<< orphan*/ ) ; 
 scalar_t__ blk_rq_cur_sectors (TYPE_1__*) ; 
 scalar_t__ blk_rq_pos (TYPE_1__*) ; 
 int /*<<< orphan*/  blk_rq_sectors (TYPE_1__*) ; 
 int /*<<< orphan*/  do_pf_read ; 
 int /*<<< orphan*/  do_pf_write ; 
 scalar_t__ get_capacity (TYPE_4__*) ; 
 scalar_t__ pf_block ; 
 int /*<<< orphan*/  pf_buf ; 
 int pf_busy ; 
 scalar_t__ pf_cmd ; 
 scalar_t__ pf_count ; 
 TYPE_3__* pf_current ; 
 int /*<<< orphan*/  pf_end_request (int /*<<< orphan*/ ) ; 
 TYPE_1__* pf_req ; 
 scalar_t__ pf_retries ; 
 int /*<<< orphan*/  pf_run ; 
 int /*<<< orphan*/  pi_do_claimed (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ rq_data_dir (TYPE_1__*) ; 
 int /*<<< orphan*/  set_next_request () ; 

__attribute__((used)) static void pf_request(void)
{
	if (pf_busy)
		return;
repeat:
	if (!pf_req && !set_next_request())
		return;

	pf_current = pf_req->rq_disk->private_data;
	pf_block = blk_rq_pos(pf_req);
	pf_run = blk_rq_sectors(pf_req);
	pf_count = blk_rq_cur_sectors(pf_req);

	if (pf_block + pf_count > get_capacity(pf_req->rq_disk)) {
		pf_end_request(BLK_STS_IOERR);
		goto repeat;
	}

	pf_cmd = rq_data_dir(pf_req);
	pf_buf = bio_data(pf_req->bio);
	pf_retries = 0;

	pf_busy = 1;
	if (pf_cmd == READ)
		pi_do_claimed(pf_current->pi, do_pf_read);
	else if (pf_cmd == WRITE)
		pi_do_claimed(pf_current->pi, do_pf_write);
	else {
		pf_busy = 0;
		pf_end_request(BLK_STS_IOERR);
		goto repeat;
	}
}