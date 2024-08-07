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
struct vnic_rq {int dummy; } ;

/* Variables and functions */
 int stub1 (struct vnic_rq*) ; 
 int vnic_rq_desc_avail (struct vnic_rq*) ; 

__attribute__((used)) static inline int vnic_rq_fill(struct vnic_rq *rq,
	int (*buf_fill)(struct vnic_rq *rq))
{
	int err;

	while (vnic_rq_desc_avail(rq) > 1) {

		err = (*buf_fill)(rq);
		if (err)
			return err;
	}

	return 0;
}