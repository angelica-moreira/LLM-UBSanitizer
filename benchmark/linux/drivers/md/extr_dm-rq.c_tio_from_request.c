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
struct request {int dummy; } ;
struct dm_rq_target_io {int dummy; } ;

/* Variables and functions */
 struct dm_rq_target_io* blk_mq_rq_to_pdu (struct request*) ; 

__attribute__((used)) static struct dm_rq_target_io *tio_from_request(struct request *rq)
{
	return blk_mq_rq_to_pdu(rq);
}