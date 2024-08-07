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
struct st_partstat {int drv_block; int drv_file; scalar_t__ last_block_valid; scalar_t__ at_sm; int /*<<< orphan*/  eof; int /*<<< orphan*/  rw; } ;
struct scsi_tape {scalar_t__ partition; scalar_t__ new_partition; scalar_t__ can_partitions; struct st_partstat* ps; scalar_t__ pos_unknown; } ;

/* Variables and functions */
 int /*<<< orphan*/  ST_IDLE ; 
 int ST_NBR_PARTITIONS ; 
 int /*<<< orphan*/  ST_NOEOF ; 
 scalar_t__ find_partition (struct scsi_tape*) ; 

__attribute__((used)) static void reset_state(struct scsi_tape *STp)
{
	int i;
	struct st_partstat *STps;

	STp->pos_unknown = 0;
	for (i = 0; i < ST_NBR_PARTITIONS; i++) {
		STps = &(STp->ps[i]);
		STps->rw = ST_IDLE;
		STps->eof = ST_NOEOF;
		STps->at_sm = 0;
		STps->last_block_valid = 0;
		STps->drv_block = -1;
		STps->drv_file = -1;
	}
	if (STp->can_partitions) {
		STp->partition = find_partition(STp);
		if (STp->partition < 0)
			STp->partition = 0;
		STp->new_partition = STp->partition;
	}
}