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
struct dm_target {int dummy; } ;
struct clone_info {struct bio* bio; } ;
struct bio {int dummy; } ;

/* Variables and functions */
 scalar_t__ REQ_OP_DISCARD ; 
 scalar_t__ REQ_OP_SECURE_ERASE ; 
 scalar_t__ REQ_OP_WRITE_SAME ; 
 scalar_t__ REQ_OP_WRITE_ZEROES ; 
 int __send_discard (struct clone_info*,struct dm_target*) ; 
 int __send_secure_erase (struct clone_info*,struct dm_target*) ; 
 int __send_write_same (struct clone_info*,struct dm_target*) ; 
 int __send_write_zeroes (struct clone_info*,struct dm_target*) ; 
 scalar_t__ bio_op (struct bio*) ; 

__attribute__((used)) static bool __process_abnormal_io(struct clone_info *ci, struct dm_target *ti,
				  int *result)
{
	struct bio *bio = ci->bio;

	if (bio_op(bio) == REQ_OP_DISCARD)
		*result = __send_discard(ci, ti);
	else if (bio_op(bio) == REQ_OP_SECURE_ERASE)
		*result = __send_secure_erase(ci, ti);
	else if (bio_op(bio) == REQ_OP_WRITE_SAME)
		*result = __send_write_same(ci, ti);
	else if (bio_op(bio) == REQ_OP_WRITE_ZEROES)
		*result = __send_write_zeroes(ci, ti);
	else
		return false;

	return true;
}